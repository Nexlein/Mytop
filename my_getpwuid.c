/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** get the number of task
*/

#include "include/my.h"

char *my_getusernamefromuid(unsigned int uid)
{
    char line[1024];
    FILE *file = fopen("/etc/passwd", "r");
    unsigned int uid_in;
    char *user = malloc(sizeof(char) * 128);

    if (file == NULL) {
        perror("fopen: Can't open /etc/passwd");
        return NULL;
    }
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%255[^:]:x:%u", user, &uid_in) && uid_in == uid) {
            break;
        }
    }
    fclose(file);
    return user;
}

char *my_getuidfrompid(char *filepath)
{
    char line[256];
    unsigned int uid = -1;
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        fprintf(stderr, "filepath: %s\n", filepath);
        perror("fopen: Can't open /proc/(PID)/status");
        return NULL;
    }
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Uid:", 4) == 0) {
            sscanf(line, "Uid:\t%d", &uid);
            break;
        }
    }
    fclose(file);
    return my_getusernamefromuid(uid);
}
