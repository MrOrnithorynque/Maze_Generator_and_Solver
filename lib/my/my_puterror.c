/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** print error
*/

#include "my.h"

void my_puterror(char *str)
{
    write(2, "\033[31m", 5);
    write(2, str, my_strlen(str));
    write(2, "\033[0m", 5);
}