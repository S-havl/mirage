#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_string_to_binary(const unsigned char *str);
void create_file_message_binary(const unsigned char *message);

int main(void) {
    unsigned char message[500];

    printf("Text: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    print_string_to_binary(message);
    create_file_message_binary(message);

    return 0;
}

void print_string_to_binary(const unsigned char *str) {
    while (*str) {
        unsigned char character = *str;

        for (int i = 7; i >= 0; i--) {
            int bit = (character >> i) & 1;
            printf("%d", bit);
        }

        str++;
    }

    printf("\n");
}

void create_file_message_binary(const unsigned char *message) {
    FILE *file;

    file = fopen("message.txt", "w");
    if (file == NULL) {
        printf("error");
        return;
    }

    for (int i = 0; message[i] != '\0'; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            fprintf(file, "%d", (message[i] >> bit) & 1);
        }
    }

    fclose(file);
}
