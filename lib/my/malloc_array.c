/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** malloc_array
*/

#include "my.h"

char *malloc_array(int cols)
{
    char *array = malloc(sizeof(char) * (cols + 1));
    if (array == NULL) {my_puterror("malloc failed");return NULL;}
    array[cols] = '\0';

    return array;
}

char **malloc_2d_array(int lines, int cols)
{
    char **array = malloc(sizeof(char *) * (lines + 1));

    if (array == NULL) {my_puterror("malloc failed"); return NULL;}
    for (int i = 0; i < lines; i++) {
        array[i] = malloc(sizeof(char) * (cols + 1));
        if (array[i] == NULL) {my_puterror("malloc failed"); return NULL;}
        array[i][cols] = '\0';
    }
    array[lines] = NULL;

    return array;
}

char ***malloc_3d_array(int lines, int cols, int depth)
{
    char ***array = malloc(sizeof(char **) * (depth + 1));

    if (array == NULL) {my_puterror("malloc failed");return NULL;}
    for (int i = 0; i < depth; i++)
    {
        array[i] = malloc(sizeof(char *) * (lines + 1));
        if (array[i] == NULL) {my_puterror("malloc failed"); return NULL;}
        for (int j = 0; j < lines; j++) {
            array[i][j] = malloc(sizeof(char) * (cols + 1));
            if (array[i][j] == NULL) {my_puterror("malloc failed"); return NULL;}
            array[i][j][cols] = '\0';
        }
        array[i][lines] = NULL;
    }
    array[depth] = NULL;

    return array;
}