/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** get command of a task
*/

#include "include/my.h"

char *format_command(char *token)
{
    int j = 0;
    int len_token = strlen(token);
    char *result = malloc(sizeof(char) * len_token + 1);

    for (int i = 1; token[i] != ')'; i++) {
        if (token[i] == '\0')
            break;
        result[j] = token[i];
        j++;
    }
    result[j] = '\0';
    return result;
}

char *my_getcommand(char *filepath)
{
    char buffer[1024];
    char *command;
    int n = 0;
    char *token;
    FILE *file = fopen(filepath, "r");

    fgets(buffer, sizeof(buffer), file);
    token = strtok(buffer, " ");
    while (token != NULL) {
        n++;
        if (n == 2) {
            command = format_command(token);
            fclose(file);
            return command;
        }
        token = strtok(NULL, " ");
    }
    fclose(file);
    free(token);
    return NULL;
}
