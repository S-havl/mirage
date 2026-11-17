#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#pragma pack(push, 1)
typedef struct ethernet_header {
    uint8_t  dest_mac_addr[6];
    uint8_t  src_mac_addr[6];
    uint16_t ethernet_type;
} ethernet_header_t;

typedef struct arp_payload {
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t  hardware_address_length;
    uint8_t  protocol_address_length;
    uint16_t operation_code;
    uint8_t  sender_hardware_address[6];
    uint8_t  sender_protocol_address[4];
    uint8_t  target_hardware_address[6];
    uint8_t  target_protocol_address[4];
} arp_payload_t;

typedef struct arp_frame {
    ethernet_header_t ethernet;
    arp_payload_t     arp;
} arp_frame_t;

typedef struct system_net_data {
    char    network_interface[16];
    uint8_t mac_address[6];
    uint8_t ip_address[4];
    int     status;
} system_net_data_t;
#pragma pack(pop)

system_net_data_t system_scan(void)
{
    system_net_data_t system_network_data;

    FILE* linux_route_file = fopen("/proc/net/route", "r");
    if (linux_route_file == NULL) {
        perror("Could not open the file: /proc/net/route");
        system_net_data_t error_data = {0};
        error_data.status            = 0;
        return error_data;
    }

    return system_network_data;
}

void arp_frame_initialization(arp_frame_t* arp_frame, const uint8_t dest_mac_address[6],
                              const uint8_t src_mac_address[6], const uint16_t ethernet_type,
                              const uint16_t hardware_type, const uint16_t protocol_type,
                              const uint8_t hardware_address_length,
                              const uint8_t protocol_address_length, const uint16_t operation_code,
                              const uint8_t sender_hardware_address[6],
                              const uint8_t sender_protocol_address[4],
                              const uint8_t target_hardware_address[6],
                              const uint8_t target_protocol_address[4])
{
    memcpy(arp_frame->ethernet.dest_mac_address, dest_mac_address, 6);
    memcpy(arp_frame->ethernet.src_mac_address, src_mac_address, 6);
    arp_frame->ethernet.ethernet_type = htons(ethernet_type);

    arp_frame->arp.hardware_type           = htons(hardware_type);
    arp_frame->arp.protocol_type           = htons(protocol_type);
    arp_frame->arp.hardware_address_length = hardware_address_length;
    arp_frame->arp.protocol_address_length = protocol_address_length;
    arp_frame->arp.operation_code          = htons(operation_code);
    memcpy(arp_frame->arp.sender_hardware_address, sender_hardware_address, 6);
    memcpy(arp_frame->arp.sender_protocol_address, sender_protocol_address, 4);
    memcpy(arp_frame->arp.target_hardware_address, target_hardware_address, 6);
    memcpy(arp_frame->arp.target_protocol_address, target_protocol_address, 4);
}

void arp_mitm(void)
{
    uint8_t arp_request_buffer[1500];
    memset(arp_request_buffer, 0, sizeof(arp_request_buffer));
    arp_frame_t* arp_request_frame = (arp_frame_t*)arp_request_buffer;
    arp_frame_initialization(arp_request_frame, (uint8_t[]){0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, ,
                             0x0806, 1, 0x0800, 6, 4, 1, ,
                             (uint8_t[]){0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, );

    uint8_t arp_reply_buffer[1500];
    memset(arp_reply_buffer, 0, sizeof(arp_reply_buffer));
    arp_frame_t* arp_reply_frame = (arp_frame_t*)arp_reply_buffer;
    arp_frame_initialization(arp_reply_frame, , , 0x0806, 1, 0x0800, 6, 4, 2, , , , );

    int raw_socketfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (raw_socketfd < 0) {
        printf("[-] Error creating the socket.\n");
        return;
    }
    printf("[+] Socket created successfully.\n");

    close(raw_socketfd);
    printf("[+] Socket closed successfully.\n");
}
