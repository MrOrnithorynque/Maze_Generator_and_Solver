/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** main
*/

#include "my.h"
#include "src.h"
#include "struct_solver.h"

int main(int ac, char **av)
{
    error_handling_solver(ac, av);

    smaze_t *maze       = maze_struct(read_file(av[1]));
    scell_t **cell      = cell_struct(maze);
    svector_t *vect     = vector_struct();
    srender_t *render   = render_struct(maze);

    water_solver(cell, maze, vect);
    render_solver(cell, maze, render);
    free_solver(cell, maze, vect);
    return 0;
}