/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#ifndef MY_H
    #define MY_H

enum cpu_field {
    CPU_US,
    CPU_NI,
    CPU_SY,
    CPU_ID,
    CPU_WA,
    CPU_HI,
    CPU_SI,
    CPU_ST,
    CPU_FIELDS
};

typedef struct taskinfo {
    char *pid;
    char *user;
    int priority;
    int nice;
    char *command;
} taskinfo_t;

typedef struct mytime {
    int seconde;
    int minute;
    int hour;
    int day;
} mytime_t;

typedef struct state {
    int sleeping;
    int stop;
    int running;
    int zombie;
    int y;
    int nbtask;
    char state;
    unsigned long long cpu_prev[CPU_FIELDS];
} state_t;

void myhour(void);
int my_getuser(void);
void bold_int(int nb);
int my_getmemused(void);
int my_getloadavg(void);
void my_getuptime(void);
void bold_float(float nb);
int isfile(char *filepath);
void header(state_t *state);
void my_getcpu(state_t *state, float *percent);
float my_getbuffcache(void);
char *make_filepath(char *pid);
float my_getmeminfo(char *str);
int my_getnice(char *filepath);
void my_getnbtask(state_t *state);
int my_getpriority(char *filepath);
char *make_filepath_stat(char *pid);
char *my_getcommand(char *filepath);
char *my_getuidfrompid(char *filepath);
void get_taskinfo(char *filepath, state_t *state);
int my_checkstate(char *filename, state_t *state);

#endif /* MY_H */
