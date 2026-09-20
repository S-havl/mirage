#include <stdio.h>
#include <input/input.h>
#include <output/output.h>
#include <file/file.h>

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
