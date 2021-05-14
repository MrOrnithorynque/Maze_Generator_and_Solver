/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Function that copies a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (;src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return dest;
}
