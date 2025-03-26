/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** get the number of task
*/

#include "include/my.h"

void print_taskinfo(state_t *state, taskinfo_t *taskinfo)
{
    mvprintw(state->y, 0, "%7s", taskinfo->pid);
    mvprintw(state->y, 8, "%s", taskinfo->user);
    if (taskinfo->priority != -100)
        mvprintw(state->y, 17, "%3d", taskinfo->priority);
    else
        mvprintw(state->y, 17, "rt");
    mvprintw(state->y, 21, "%3d", taskinfo->nice);
    mvprintw(state->y, 29, "%3d", 0);
    mvprintw(state->y, 36, "%3d", 0);
    mvprintw(state->y, 43, "%3d", 0);
    mvprintw(state->y, 47, "%c", state->state);
    mvprintw(state->y, 51, "%3.1f", 0.0);
    mvprintw(state->y, 57, "%3.1f", 0.0);
    mvprintw(state->y, 62, "%2d:%.2d.%.2d", 0, 0, 0);
    mvprintw(state->y, 71, "%s", taskinfo->command);
}

void free_all(taskinfo_t *taskinfo)
{
    free(taskinfo->user);
    free(taskinfo);
}

void get_taskinfo(char *pid, state_t *state)
{
    taskinfo_t *taskinfo = malloc(sizeof(taskinfo_t));
    char *filepath = make_filepath(pid);
    char *filepathstat = make_filepath_stat(pid);

    taskinfo->pid = pid;
    taskinfo->user = my_getuidfrompid(filepath);
    taskinfo->priority = my_getpriority(filepathstat);
    taskinfo->nice = my_getnice(filepathstat);
    taskinfo->command = my_getcommand(filepathstat);
    print_taskinfo(state, taskinfo);
    state->y++;
    free(taskinfo->command);
    free_all(taskinfo);
    free(filepath);
    free(filepathstat);
}
