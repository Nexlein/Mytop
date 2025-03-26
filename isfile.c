/*
** EPITECH PROJECT, 2024
** top
** File description:
** isfile
*/

#include "include/my.h"

int isfile(char *filepath)
{
    struct stat f_stat;

    if (stat(filepath, &f_stat) == -1) {
        perror("stat");
        return 84;
    }
    if (S_ISREG(f_stat.st_mode))
        return 0;
    return 84;
}
