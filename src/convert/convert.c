#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

static int get_user_input(char *buffer, size_t size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

static int print_string_to_binary(const char *str)
{
    if (str == NULL) {
        return 0;
    }

    while (*str) {
        unsigned char character = *str;

        for (int i = 7; i >= 0; i--) {
            int bit = (character >> i) & 1;
            printf("%d", bit);
        }

        str++;
    }

    printf("\n");
    return 1;
}

static int create_file_message_binary(const char *message)
{
    FILE *file;

    file = fopen("message.txt", "w");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; message[i] != '\0'; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            fprintf(file, "%d", (message[i] >> bit) & 1);
        }
    }

    fclose(file);
    return 1;
}

void convert_text_to_binary(void)
{
    char message[MAX_INPUT_SIZE];

    printf("\n[CONVERT] Enter text to convert: ");
    if (!get_user_input(message, sizeof(message))) {
        return;
    }

    if (!print_string_to_binary(message)) {
        fprintf(stderr, "Critical error: Could not convert string to binary.\n");
        return;
    }

    if (!create_file_message_binary(message)) {
        fprintf(stderr, "Critical error: Could not save the binary file.\n");
        return;
    }

    printf("Message successfully converted.\n");
}
