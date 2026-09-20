#pragma once

typedef enum {
    STATE_MENU,
    STATE_CONVERT,
    STATE_ENCODE,
    STATE_DECODE,
    STATE_EXIT
} appState_t;

appState_t app(appState_t current_state);
