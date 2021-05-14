/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** generator
*/

#include "my.h"
#include "struct_generator.h"
#include "src.h"

static void exception(int lines, int cols)
{
    if (lines == 1)
        for (int i = 0; i < cols; write(1, "*", 1), i++);
    else if (cols == 1)
        for (int i = 0; i < lines; write(1, "*\n", 2), i++);
    else
        return;

    exit(0);
}

int main(int ac, char **av)
{
    int flag = 0;

    error_handling_generation(ac, av);

    maze_t *maze = fill_maze_struct(my_getnbr(av[1]), my_getnbr(av[2]));
    cell_t **cell = create_tab_cell_struct(maze);

    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        flag = 1;
    if (my_getnbr(av[1]) == 1 || my_getnbr(av[2]) == 1)
        exception(my_getnbr(av[1]), my_getnbr(av[2]));

    depth_first_search(cell, maze, flag);
    free_generator(cell, maze);

    return 0;
}