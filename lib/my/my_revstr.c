/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** fonction importante
*/

#include "my.h"

char *my_revstr(char *str)
{
    char tmp;
    int i = 0;
    int len;

    len = my_strlen(str) - 1;
    while (i <= len / 2) {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
        i++;
    }

    return str;
}
