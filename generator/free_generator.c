/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** free_generator
*/

#include "my.h"
#include "struct_generator.h"

void free_generator(cell_t **cell, maze_t *maze)
{
    for (int i = 0; i < maze->nb_blocks; i++) {
        free(cell[i]->neighbors);
        free(cell[i]->wall);
        free(cell[i]);
    }
    free(cell);

    for (int i = 0; i < maze->lines; i++)
        free(maze->maze_map[i]);
    free(maze->maze_map);
    free(maze);
}