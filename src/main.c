#include <app/app.h>
#include <stdio.h>

int main(void)
{
    appState_t current_state = STATE_MENU;

    while (current_state != STATE_EXIT) {
        current_state = app(current_state);
    }

    printf("Leaving Mirage. Goodbye\n");

    return 0;
}
