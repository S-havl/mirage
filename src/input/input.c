#include <stdio.h>
#include <string.h>
#include <input/input.h>

int get_user_input(char *buffer, size_t size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}
