/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** yes
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (; s1[n] != '\0'; n++) {
        if (s1[n] != s2[n])
            return n;
    }

    return 0;
}
