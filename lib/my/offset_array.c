/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** offset_array
*/

#include "my.h"

char **offset_array(char **tab, size_t offset)
{
    for (; tab[offset + 1] != NULL; ++offset) {
        free(tab[offset]);
        tab[offset] = my_strdup(tab[offset + 1]);
    }
    free(tab[my_tablen((void **)tab)]);
    tab[offset] = NULL;

    return tab;
}
