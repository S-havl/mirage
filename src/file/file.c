#include <stdio.h>

int create_file_message_binary(const char *message) {
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
