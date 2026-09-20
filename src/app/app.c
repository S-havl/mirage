#include <stdio.h>
#include <app/app.h>
#include <convert/convert.h>

appState_t app(appState_t current_state)
{
    int option = 0;

    switch (current_state) {

        case STATE_MENU:
            printf("\n=== MIRAGE CLI ===\n");
            printf("1. Convert text to binary\n");
            printf("2. Encode text\n");
            printf("3. Decode text\n");
            printf("4. Exit\n");
            printf("Select an option: ");

            if (scanf("%d", &option) != 1) {
                while (getchar() != '\n');
                printf("Invalid option.\n");
                return STATE_MENU;
            }
            while (getchar() != '\n');

            if (option == 1) return STATE_CONVERT;
            if (option == 2) return STATE_ENCODE;
            if (option == 3) return STATE_DECODE;
            if (option == 4) return STATE_EXIT;

            printf("Invalid option. Try again.\n");
            return STATE_MENU;

	case STATE_CONVERT:
            convert_text_to_binary();
            return STATE_MENU;

	case STATE_ENCODE:


        case STATE_DECODE:


	case STATE_EXIT:


    }

    return STATE_MENU;
}
