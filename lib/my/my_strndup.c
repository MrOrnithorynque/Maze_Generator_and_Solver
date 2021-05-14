/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char const *src, int n)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1 - n));

    for (size_t i = 0 ;src[i] != '\0'; ++i)
        str[i] = src[n + i];
    str[len - n] = '\0';

    return str;
}