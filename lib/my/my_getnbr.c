/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** fonction importante
*/

#include "my.h"

static int num(char const *str)
{
    int b = 0;

    for (int i = 0; (str[i] < '0' && str[i] > '9') || str[i] != '\0'; i++)
    {
        while (str[i] >= '0' && str[i] <= '9')
            return b;
        b++;
    }
    return 0;
}

static long op(char const *str, long result)
{
    for (int a = 0; (str[a] < '0' && str[a] > '9') || str[a] != '\0'; a++)
    {
        while (str[a] >= '0' && str[a] <= '9')
            return result;
        (str[a] == '-') ? result = result * -1 : 0;
    }
    return result;
}

long my_getnbr(char const *str)
{
    long result = 0;
    int i = num(str);

    for (;(str[i] >= '0') && (str[i] <= '9'); i++)
        result = result * 10 + (str[i] - '0');

    result = op(str, result);

    return result;
}
