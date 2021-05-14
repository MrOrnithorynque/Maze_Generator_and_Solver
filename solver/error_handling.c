/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** error_handling
*/

#include "my.h"

static void nb_arguments(int ac)
{
    if (ac != 2)
    {
        my_puterror("error : incorrect number of arguments.\n");
        exit(84);
    }
}

static void check_file(char *file)
{
    if (read_file(file) == NULL)
        exit(84);
}

static void check_map(char *map)
{
    int cols = 0;
    int cols_in_line = 0;

    for (; map[cols] != '\n'; cols++);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '*' && map[i] != 'X' && map[i] != '\n') {
            my_puterror("error : incorrect map.\n");
            exit(84);
        }
        cols_in_line++;
        if (map[i] == '\n') {
            cols_in_line -= 1;
            if (cols_in_line != cols) {
                my_puterror("error : incorrect number of colones.\n");
                exit(84);
            }
            cols_in_line = 0;
        }
    }
}

void error_handling_solver(int ac, char **av)
{
    nb_arguments(ac);
    check_file(av[1]);
    check_map(read_file(av[1]));
}