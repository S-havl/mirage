#include <stdio.h>
#include "../input/input.h"
#include "../output/output.h"
#include "../file/file.h"

void app(void) {
    char message[MAX_INPUT_SIZE];

    while (1) {
        printf("Text: ");
        if (!get_user_input(message, sizeof(message))) {
            break;
        }

        print_string_to_binary(message);

        if (!create_file_message_binary(message)) {
            fprintf(stderr, "Critical error: Could not save the binary file.\n");
        }
    }
}
