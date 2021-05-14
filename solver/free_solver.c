/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** free_solver
*/

#include "my.h"
#include "struct_solver.h"

void free_solver(scell_t **cell, smaze_t *maze, svector_t *vect)
{
    for (int i = 0; i < maze->nb_blocks; i++)
        free(cell[i]);
    free(cell);

    for (int i = 0; i < maze->lines; i++)
        free(maze->maze_map[i]);
    free(maze->maze_map);
    free(maze);

    for (int i = 0; i < 4; i++)
        free(vect->vector[i]);
    free(vect->vector);
    free(vect);
}