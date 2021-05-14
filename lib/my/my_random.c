/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** random
*/

#include "my.h"

int random_from_address(int address, int min, int max)
{
    int random = address / 10;

    (random < 0) ? random *= -1 : 0;
    random = min + (random % max);

    return random;
}

int my_random(int min, int max)
{
    return rand();
}