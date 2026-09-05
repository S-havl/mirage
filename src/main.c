#include <stdio.h>
#include <app/app.h>

int main(void)
{
    appState_t current_state = STATE_MENU;
    int option = 0;

    while (current_state != STATE_EXIT) {
        app();
    }

    return 0;
}
