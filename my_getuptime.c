/*
** EPITECH PROJECT, 2024
** getuptime
** File description:
** getuptime
*/

#include "include/my.h"

void check_day(mytime_t *mytime)
{
    while (mytime->hour >= 24) {
        mytime->day++;
        mytime->hour -= 24;
    }
    if (mytime->hour == 0)
        printw(" %d day, %d min,", mytime->day, mytime->minute);
    else if (mytime->minute < 10)
        printw(" %d day, %d:0%d,", mytime->day, mytime->hour, mytime->minute);
    else
        printw(" %d day, %d:%d,", mytime->day, mytime->hour, mytime->minute);
}

void calculate(mytime_t *mytime, char *result)
{
    mytime->seconde = atoi(result);
    mytime->minute = mytime->seconde / 60;
    mytime->hour = mytime->minute / 60;
    mytime->minute -= mytime->hour * 60;
    if (mytime->hour >= 24) {
        check_day(mytime);
    }
    if (mytime->hour == 0)
        printw(" %d min,", mytime->minute);
    else if (mytime->minute < 10)
        printw(" %d:0%d,", mytime->hour, mytime->minute);
    else
        printw(" %d:%d,", mytime->hour, mytime->minute);
}

void my_getuptime(void)
{
    mytime_t *mytime = malloc(sizeof(mytime_t));
    int fd = open("/proc/uptime", O_RDONLY);
    char buffer[BUFSIZ + 1];
    char result[128];

    if (fd == 0) {
        perror("open");
        return;
    }
    read(fd, buffer, sizeof(buffer));
    for (int i = 0; buffer[i] != ' '; i++)
        result[i] = buffer[i];
    calculate(mytime, result);
    free(mytime);
    close(fd);
}
