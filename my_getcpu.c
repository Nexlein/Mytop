/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** CPU usage from /proc/stat, between two refreshes
*/

#include "include/my.h"

static int read_cpu(unsigned long long *ticks)
{
    FILE *fd = fopen("/proc/stat", "r");
    int read = 0;

    if (fd == NULL)
        return 84;
    read = fscanf(fd, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
        &ticks[CPU_US], &ticks[CPU_NI], &ticks[CPU_SY], &ticks[CPU_ID],
        &ticks[CPU_WA], &ticks[CPU_HI], &ticks[CPU_SI], &ticks[CPU_ST]);
    fclose(fd);
    return read == CPU_FIELDS ? 0 : 84;
}

void my_getcpu(state_t *state, float *percent)
{
    unsigned long long ticks[CPU_FIELDS] = {0};
    unsigned long long delta[CPU_FIELDS] = {0};
    unsigned long long total = 0;

    if (read_cpu(ticks) != 0)
        return;
    for (int i = 0; i < CPU_FIELDS; i++) {
        delta[i] = ticks[i] - state->cpu_prev[i];
        total += delta[i];
        state->cpu_prev[i] = ticks[i];
    }
    for (int i = 0; i < CPU_FIELDS && total > 0; i++)
        percent[i] = (float)delta[i] * 100.0 / (float)total;
}
