/*
** EPITECH PROJECT, 2024
** get load avg
** File description:
** get the load average
*/

#include "include/my.h"

int my_getloadavg(void)
{
    FILE *fd = fopen("/proc/loadavg", "r");
    char *loadavg = malloc(sizeof(char) * 15);

    if (fd == NULL) {
        perror("fopen");
        return 84;
    }
    fgets(loadavg, 15, fd);
    if (loadavg == NULL) {
        perror("fgets");
        fclose(fd);
        return 84;
    }
    printw("load average: %s\n", loadavg);
    free(loadavg);
    fclose(fd);
    return 0;
}
