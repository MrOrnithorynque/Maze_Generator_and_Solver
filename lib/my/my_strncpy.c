/*
** EPITECH PROJECT, 2020
** strncpy.c
** File description:
** yes
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    for (;src[i] != '\0' && i < len; i++)
        dest[n + i] = src[i];
    dest[n + i] = '\0';

    return dest;
}
