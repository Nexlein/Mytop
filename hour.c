/*
** EPITECH PROJECT, 2024
** Boostrap myls
** File description:
** Boostrap myls
*/

#include "include/my.h"

void myhour(void)
{
    time_t time_total = time(NULL);
    struct tm *hour = localtime(&time_total);

    printw("%.2d:%.2d:%.2d up ", hour->tm_hour, hour->tm_min, hour->tm_sec);
}
