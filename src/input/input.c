#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../output/output.h"
#include "../file/file.h"

void input(void) {
    char message[500];

    while (1) {
        printf("Text: ");
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = '\0';

        print_string_to_binary(message);
        create_file_message_binary(message);
    }
}
