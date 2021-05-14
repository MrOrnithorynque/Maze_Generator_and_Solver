/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** my_get_float
*/

#include "my.h"

float cat_int_float(char *decimal, char *integer, int nb_flt)
{
    float result;
    int power = 1;

    for (int i = 0; i < nb_flt; i++)
        power = power * 10;

    result = my_getnbr(decimal);
    result = result / power;
    nb_flt = my_getnbr(integer);
    (nb_flt < 0) ? result = nb_flt - result : nb_flt + result;
    (nb_flt == 0) ? result = result * -1 : 0;

    return result;
}

float my_get_float(char *str)
{
    int flt = -1;
    int nb = 0;
    char *decimal = malloc(sizeof(char) * my_strlen(str) + 1);

    decimal = my_strcpy(decimal, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.')
        {
            flt = i;
            for (i++; str[i] != '\0'; i++)
                nb++;
            for (i = 0; str[i + flt + 1] != '\0'; i++)
                decimal[i] = str[i + flt + 1];
            decimal[i] = '\0';
            break;
        }
    }

    return cat_int_float(decimal, str, nb);
}