/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** task01 Write a function that allocates memory and copies
** the string given as argument in it.
*/

#include "my.h"

char *my_strdup(char const *arc)
{
    char *str;
    int i = 0;

    for (;arc[i] != '\0'; i++);
    str = malloc(sizeof(char) * (i + 1));
    i = 0;

    for (;arc[i] != '\0'; i++)
        str[i] = arc[i];
    str[i] = '\0';

    return str;
}
