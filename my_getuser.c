/*
** EPITECH PROJECT, 2024
** get user
** File description:
** get the number
*/

#include "include/my.h"

int my_getuser()
{
    FILE *fn;
    char buffer[1024];
    int count = 0;

    fn = popen("who | wc -l", "r");
    if (fn == NULL) {
        perror("popen");
        return 84;
    }
    if (fgets(buffer, sizeof(buffer), fn) != NULL) {
        count = atoi(buffer);
    }
    printw("%d user,  ", count);
    pclose(fn);
    return 0;
}
