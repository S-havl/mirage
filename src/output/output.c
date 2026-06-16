#include <stdio.h>

int print_string_to_binary(const char *str) {
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

