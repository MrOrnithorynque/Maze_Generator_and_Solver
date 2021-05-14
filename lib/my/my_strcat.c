/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concat 2 strings togethe;r
*/

#include "my.h"

char *my_strcat(char *dest, char  const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int j = 0;
    int k = 0;

    for (int i = 0; src[i] != '\0'; i++)
    {
        for (; dest[k] != '\0'; k++)
        {
            str[j] = dest[k];
            j++;
        }
        str[j] = src[i];
        j++;
    }
    str[j] = '\0';

    return str;
}