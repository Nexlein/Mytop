/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** header top
*/

#include "include/my.h"

void bold_float(float nb)
{
    attron(A_BOLD);
    printw("%.1f", nb);
    attroff(A_BOLD);
}

void bold_int(int nb)
{
    attron(A_BOLD);
    printw("%d", nb);
    attroff(A_BOLD);
}
