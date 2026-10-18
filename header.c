/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** header top
*/

#include "include/my.h"

static void first_line(void)
{
    mvprintw(0, 0, "top - ");
    myhour();
    my_getuptime();
    printw("  ");
    my_getuser();
    my_getloadavg();
}

static void second_line(state_t *state)
{
    my_getnbtask(state);
    bold_int(state->running);
    printw(" running, ");
    bold_int(state->sleeping);
    printw(" sleeping,   ");
    bold_int(state->stop);
    printw(" stopped,   ");
    bold_int(state->zombie);
    printw(" zombie\n");
}

static void third_line(state_t *state)
{
    float cpu[CPU_FIELDS] = {0};

    my_getcpu(state, cpu);
    printw("%%Cpu(s):  ");
    bold_float(cpu[CPU_US]);
    printw(" us,  ");
    bold_float(cpu[CPU_SY]);
    printw(" sy,  ");
    bold_float(cpu[CPU_NI]);
    printw(" ni, ");
    bold_float(cpu[CPU_ID]);
    printw(" id,  ");
    bold_float(cpu[CPU_WA]);
    printw(" wa,  ");
    bold_float(cpu[CPU_HI]);
    printw(" hi,  ");
    bold_float(cpu[CPU_SI]);
    printw(" si,  ");
    bold_float(cpu[CPU_ST]);
    printw(" st\n");
}

static void fourth_line(void)
{
    printw("MiB Mem :  ");
    bold_float(my_getmeminfo("MemTotal"));
    printw(" total,  ");
    bold_float(my_getmeminfo("MemFree"));
    printw(" free,   ");
    my_getmemused();
    bold_float(my_getbuffcache());
    printw(" buff/cache\n");
}

static void fifth_line(void)
{
    printw("MiB Swap:   ");
    bold_float(my_getmeminfo("SwapTotal"));
    printw(" total,   ");
    bold_float(my_getmeminfo("SwapFree"));
    printw(" free,      ");
    bold_float(my_getmeminfo("SwapCached"));
    printw(" used.  ");
    bold_float(my_getmeminfo("MemAvailable"));
    printw(" avail Mem\n");
}

void white_line(void)
{
    char *str1 = "\n    PID USER      PR  NI    VIRT";
    char *str2 = "    RES    SHR S  %CPU  %MEM     TIME+ COMMAND";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char string[len1 + len2 + 1];

    memset(string, '\0', sizeof(char) * len1 + len2 + 1);
    strcat(string, str1);
    strcat(string, str2);
    attron(A_STANDOUT);
    printw("%s", string);
    for (int i = len1 + len2; i < COLS - 1; i++)
        printw(" ");
    printw("\n");
    attroff(A_STANDOUT);
}

void header(state_t *state)
{
    first_line();
    second_line(state);
    third_line(state);
    fourth_line();
    fifth_line();
    white_line();
}
