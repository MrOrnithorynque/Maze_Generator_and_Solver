/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-louis.obeniche-rousse
** File description:
** modulo
*/

#include "my.h"

float modulo(float x, float y)
{
    float result;
    int z;

    if (x == y)
        return 0;
    else if (y > x)
        return x;
    else {
        z = x / y;
        result = x - (z * y);
    }
    return result;
}