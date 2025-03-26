/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** get prority of a task
*/

#include "include/my.h"

int my_getnice(char *filepath)
{
    char buffer[1024];
    int nice;
    int n = 0;
    char *token;
    FILE *file = fopen(filepath, "r");

    fgets(buffer, sizeof(buffer), file);
    token = strtok(buffer, " ");
    while (token != NULL) {
        n++;
        if (n == 19) {
            nice = atoi(token);
            fclose(file);
            return nice;
        }
        token = strtok(NULL, " ");
    }
    fclose(file);
    return 84;
}
