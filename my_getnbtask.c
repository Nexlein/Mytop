/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** get the number of task
*/

#include "include/my.h"

void init_state(state_t *state)
{
    state->y = 7;
    state->stop = 0;
    state->nbtask = 0;
    state->zombie = 0;
    state->running = 0;
    state->sleeping = 0;
}

void my_getnbtask(state_t *state)
{
    struct dirent *entry;
    DIR *dir = opendir("/proc");

    init_state(state);
    entry = readdir(dir);
    while (entry != NULL) {
        if (isdigit(entry->d_name[0])) {
            state->nbtask++;
            my_checkstate(entry->d_name, state);
            get_taskinfo(entry->d_name, state);
        }
        entry = readdir(dir);
    }
    mvprintw(1, 0, "Tasks: ");
    bold_int(state->nbtask);
    printw(" total,   ");
    closedir(dir);
}
