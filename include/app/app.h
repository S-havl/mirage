#pragma once

typedef enum {
    STATE_MENU,
    STATE_ENCODE,
    STATE_DECODE,
    STATE_EXIT
} appState_t;

void app(void);
