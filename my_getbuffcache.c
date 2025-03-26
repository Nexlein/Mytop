/*
** EPITECH PROJECT, 2024
** getuptime
** File description:
** getmemtotal
*/

#include "include/my.h"

float my_getbuffcache(void)
{
    float mem_cache = my_getmeminfo("Cached");
    float mem_buff = my_getmeminfo("Buffers");
    float mem_reclaim = my_getmeminfo("SReclaimable");

    return mem_cache + mem_buff + mem_reclaim;
}
