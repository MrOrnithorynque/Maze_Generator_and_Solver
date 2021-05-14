/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** error_handling
*/

#include "my.h"

static void correct_arguments(char **av)
{
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
    {
        my_puterror("error : x and y must be a number greater than 0.\n");
        exit(84);
    }
}

static void nb_arguments(int ac, char **av)
{
    if (ac > 4 || ac < 3)
    {
        my_puterror("error : incorrect number of arguments.\n");
        exit(84);
    }
    if (ac == 4 && my_strcmp(av[3], "perfect") != 0)
    {
        my_puterror("error : optional argument incorrect, try typing"
        " 'perfect'.\n");
        exit(84);
    }
}

static void is_arg_nb(int ac, char **av)
{
    if (ac != 3)
        return;
    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < my_strlen(av[i]); j++) {
            if (av[i][j] < '0' || av[i][j] > '9')
            {
                my_puterror("error : argument must be a number.\n");
                exit(84);
            }
        }
    }
}

void error_handling_generation(int ac, char **av)
{
    is_arg_nb(ac, av);
    nb_arguments(ac, av);
    correct_arguments(av);
}
