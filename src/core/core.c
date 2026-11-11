#include <console/console.h>
#include <core/core.h>
#include <modules/modules.h>

#include <stdio.h>
#include <stdlib.h>
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

void handle_root_command(framework_context_t* framework_context, const char* input_cmd)
{
    if (strcmp(input_cmd, "exit") == 0) {
        printf(SCAPE_ANSI_COLOR_RED "[*] Leaving Mirage...\n" SCAPE_ANSI_RESET);
        exit(0);
    } else if (strcmp(input_cmd, "help") == 0) {
        printf(SCAPE_ANSI_COLOR_CYAN "[*] Main commands:\n" SCAPE_ANSI_RESET);
        printf(SCAPE_ANSI_COLOR_CYAN "use <module>" SCAPE_ANSI_RESET "   - Select a module\n");
        printf(SCAPE_ANSI_COLOR_CYAN "help" SCAPE_ANSI_RESET "           - Show this help\n");
        printf(SCAPE_ANSI_COLOR_CYAN "clear" SCAPE_ANSI_RESET "          - Clear screen\n");
        printf(SCAPE_ANSI_COLOR_CYAN "exit" SCAPE_ANSI_RESET "           - Leave Mirage\n");
    } else if (strcmp(input_cmd, "clear") == 0) {
        print_banner();
    } else if (strcmp(input_cmd, "use") == 0) {
        char* module_argument = strtok(NULL, " ");
        if (module_argument != NULL) {
            module_descriptor_t* module = search_for_module(module_argument);
            if (module != NULL) {
                framework_context->current_state = STATE_FRAMEWORK_MODULE_ACTIVE;
                framework_context->active_module = module;

                printf(SCAPE_ANSI_COLOR_GREEN "[+] Entering the module:" SCAPE_ANSI_COLOR_GREEN_BOLD
                                              " %s\n" SCAPE_ANSI_RESET,
                       framework_context->active_module->module_name);
            } else {
                printf(SCAPE_ANSI_COLOR_RED "[-] Module not found:" SCAPE_ANSI_COLOR_RED_BOLD
                                            " %s\n" SCAPE_ANSI_RESET,
                       module_argument);
            }
        } else {
            printf(SCAPE_ANSI_COLOR_RED "[-] Usage:" SCAPE_ANSI_RESET " use <module_name>\n");
        }
    } else {
        printf(SCAPE_ANSI_COLOR_RED "[-] Unknown command: " SCAPE_ANSI_COLOR_CYAN
                                    "%s. " SCAPE_ANSI_RESET "Type 'help'.\n",
               input_cmd);
    }
}

void handle_module_command(framework_context_t* framework_context, const char* input_cmd)
{
    if (strcmp(input_cmd, "back") == 0) {
        printf(SCAPE_ANSI_COLOR_RED "[*] Leaving the module...\n" SCAPE_ANSI_RESET);
        framework_context->current_state = STATE_ROOT;
        framework_context->active_module = NULL;
    } else if (strcmp(input_cmd, "help") == 0) {
        printf(SCAPE_ANSI_COLOR_CYAN "[*] Module commands:\n" SCAPE_ANSI_RESET);
        printf(SCAPE_ANSI_COLOR_CYAN "back" SCAPE_ANSI_RESET "   - Return to the main menu\n");
        printf(SCAPE_ANSI_COLOR_CYAN "run" SCAPE_ANSI_RESET "    - Execute the module action\n");
        printf(SCAPE_ANSI_COLOR_CYAN "clear" SCAPE_ANSI_RESET "    - Clear screen\n");
    } else if (strcmp(input_cmd, "clear") == 0) {
        print_banner();
    } else if (strcmp(input_cmd, "run") == 0) {
        if (framework_context->active_module != NULL &&
            framework_context->active_module->module_function != NULL) {
            printf(SCAPE_ANSI_COLOR_GREEN "[+] Executing the module...\n" SCAPE_ANSI_RESET);
            framework_context->active_module->module_function();
        } else {
            printf(SCAPE_ANSI_COLOR_RED
                   "[-] No executable function found for this module.\n" SCAPE_ANSI_RESET);
        }
    } else {
        printf(SCAPE_ANSI_COLOR_RED "[-] Unknown command in module:" SCAPE_ANSI_COLOR_CYAN
                                    " %s\n" SCAPE_ANSI_RESET,
               input_cmd);
    }
}

void start_framework(void)
{
    char input[MAX_INPUT_SIZE];

    framework_context_t framework_context = {.current_state = STATE_ROOT, .active_module = NULL};

    while (1) {
        switch (framework_context.current_state) {
            case STATE_ROOT:
                printf(SCAPE_ANSI_UNDERLINE_BLUE "mirage" SCAPE_ANSI_RESET " > ");
                break;
            case STATE_FRAMEWORK_MODULE_ACTIVE:
                printf(SCAPE_ANSI_UNDERLINE_BLUE "%s" SCAPE_ANSI_RESET " > ",
                       framework_context.active_module->module_name);
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

        if (framework_context.current_state == STATE_ROOT) {
            handle_root_command(&framework_context, input_cmd);
        } else if (framework_context.current_state == STATE_FRAMEWORK_MODULE_ACTIVE) {
            handle_module_command(&framework_context, input_cmd);
        }
    }
}
