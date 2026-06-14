#include <stdio.h>

void print_string_to_binary(const char *str) {
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

