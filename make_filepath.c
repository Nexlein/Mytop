/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** make a file path with /proc/(PID)/status
*/

#include "include/my.h"

char *make_filepath(char *pid)
{
    int len_pid = strlen(pid);
    char *proc = "/proc/";
    int len_proc = strlen(proc);
    char *status = "/status";
    int len_status = strlen(status);
    int len_total = len_proc + len_pid + len_status;
    char *filepath = malloc(sizeof(char) * len_total + 1);

    memset(filepath, '\0', sizeof(char) * len_total + 1);
    strcat(filepath, proc);
    strcat(filepath, pid);
    strcat(filepath, status);
    return filepath;
}

char *make_filepath_stat(char *pid)
{
    int len_pid = strlen(pid);
    char *proc = "/proc/";
    int len_proc = strlen(proc);
    char *stat = "/stat";
    int len_status = strlen(stat);
    int len_total = len_proc + len_pid + len_status;
    char *filepath = malloc(sizeof(char) * len_total + 1);

    memset(filepath, '\0', sizeof(char) * len_total + 1);
    strcat(filepath, proc);
    strcat(filepath, pid);
    strcat(filepath, stat);
    return filepath;
}
