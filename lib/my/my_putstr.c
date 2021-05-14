/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** fonction importante.
*/

#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
