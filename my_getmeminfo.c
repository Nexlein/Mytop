/*
** EPITECH PROJECT, 2024
** getuptime
** File description:
** getmemtotal
*/

#include "include/my.h"

float loop(char *str, int len, FILE *fd)
{
    char line[256];
    char string[len + 6];
    long mem_info = -1;

    string[0] = '\0';
    strcat(string, str);
    strcat(string, ": %ld");
    while (fgets(line, sizeof(line), fd)) {
        if (strncmp(line, str, len) == 0) {
            sscanf(line, string, &mem_info);
            break;
        }
    }
    return mem_info;
}

float my_getmeminfo(char *str)
{
    int len = strlen(str);
    long mem_info = -1;
    FILE *fd = fopen("/proc/meminfo", "r");

    if (fd == NULL) {
        perror("Failed to open /proc/meminfo");
        return 84;
    }
    mem_info = loop(str, len, fd);
    fclose(fd);
    return ((float)mem_info / 1024.0);
}
