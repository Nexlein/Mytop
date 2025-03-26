/*
** EPITECH PROJECT, 2024
** getuptime
** File description:
** get the memory used by substractin memory free to memory total
*/

#include "include/my.h"

int my_getmemused(void)
{
    float mem_total = my_getmeminfo("MemTotal");
    float mem_available = my_getmeminfo("MemAvailable");
    float mem_used = mem_total - mem_available;

    bold_float(mem_used);
    printw(" used,   ");
    return 0;
}
