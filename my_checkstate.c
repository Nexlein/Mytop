/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** check the state of a task
*/

#include "include/my.h"

void increment(char *ptr, state_t *state)
{
    if (ptr[7] == 'S' || ptr[7] == 'I' || ptr[7] == 'D' || ptr[7] == 'W')
        state->sleeping++;
    if (ptr[7] == 'T')
        state->stop++;
    if (ptr[7] == 'Z')
        state->zombie++;
    if (ptr[7] == 'R')
        state->running++;
    state->state = ptr[7];
}

int my_checkstate(char *filename, state_t *state)
{
    char *filepath = make_filepath(filename);
    char buffer[BUFSIZ];
    char *ptr;
    int fd = 0;

    if (isfile(filepath) == 84) {
        free(filepath);
        return 84;
    }
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 84;
    }
    read(fd, buffer, sizeof(buffer));
    ptr = strstr(buffer, "State");
    increment(ptr, state);
    free(filepath);
    close(fd);
    return 0;
}
