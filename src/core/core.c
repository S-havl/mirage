#include <console/console.h>
#include <core/core.h>

#include <stdio.h>

#define MAX_INPUT_SIZE 256

void print_banner(void)
{

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
    printf("║   [+] Offensive Hacking Framework                          ║\n");
    printf("║   [+] Loaded Modules: 0                                    ║\n");
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
        }
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;
    }
}
