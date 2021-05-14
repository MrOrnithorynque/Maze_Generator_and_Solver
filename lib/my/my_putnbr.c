/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** fonction importante
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 10);
        return;
    } if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else
        my_putchar(nb + 48);
}
