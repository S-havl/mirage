#include <console/console.h>
#include <core/core.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void print_banner(void)
{
    printf(SCAPE_ANSI_CLEAR_SCREEN);
    printf(SCAPE_ANSI_CURSOR_RESET);
    printf(SCAPE_ANSI_COLOR_PURPLE);

    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                                                            ║\n");
    printf("║   ███╗   ███╗██╗██████╗  █████╗  ██████╗ ███████╗          ║\n");
    printf("║   ████╗ ████║██║██╔══██╗██╔══██╗██╔════╝ ██╔════╝          ║\n");
    printf("║   ██╔████╔██║██║██████╔╝███████║██║  ███╗█████╗            ║\n");
    printf("║   ██║╚██╔╝██║██║██╔══██╗██╔══██║██║   ██║██╔══╝            ║\n");
    printf("║   ██║ ╚═╝ ██║██║██║  ██║██║  ██║╚██████╔╝███████╗          ║\n");
    printf("║   ╚═╝     ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝          ║\n");
    printf("║                                                            ║\n");
    printf("║   [*] Offensive Hacking Framework                          ║\n");
    printf("║   [*] Loaded Modules: 0                                    ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");

    printf(SCAPE_ANSI_RESET "\n");
}

void start_framework(void)
{
    framework_state_t current_framework_state = STATE_ROOT;
    char              input[MAX_INPUT_SIZE];

    while (1) {
        switch (current_framework_state) {
            case STATE_ROOT:
                printf(SCAPE_ANSI_UNDERLINE_BLUE "mirage" SCAPE_ANSI_RESET " > ");
                break;
            case STATE_FRAMEWORK_MODULE_ACTIVE:
                printf(SCAPE_ANSI_UNDERLINE_BLUE "module name" SCAPE_ANSI_RESET " > ");
                break;
        }
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\r\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        char* input_cmd = strtok(input, " ");
        if (input_cmd == NULL)
            continue;

        switch (current_framework_state) {
            case STATE_ROOT:
                if (strcmp(input_cmd, "exit") == 0) {
                    printf(SCAPE_ANSI_COLOR_RED "Leaving Mirage...\n" SCAPE_ANSI_RESET);
                    return;
                }
        }
    }
}
