/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** len void**
*/

#include <stdio.h>

int my_tablen(void **tab)
{
    size_t len = 0;

    for (; tab[len] != NULL; ++len);

    return len;
}