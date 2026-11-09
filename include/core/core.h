#pragma once

typedef enum framework_state { STATE_ROOT, STATE_FRAMEWORK_MODULE_ACTIVE } framework_state_t;

typedef struct framework_context {
    framework_state_t current_state;
} framework_context_t;

void print_banner(void);
void start_framework(void);
