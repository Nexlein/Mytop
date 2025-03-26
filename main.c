/*
** EPITECH PROJECT, 2024
** main top
** File description:
** main top
*/

#include "include/my.h"

int main(void)
{
    state_t *state = malloc(sizeof(state_t));
    int key = 0;
    WINDOW *window = initscr();

    noecho();
    timeout(3 * 1000);
    keypad(window, true);
    while (1) {
        clear();
        header(state);
        key = getch();
        if (key != 'q') {
            refresh();
        } else {
            endwin();
            break;
        }
    }
    free(state);
    return 0;
}
