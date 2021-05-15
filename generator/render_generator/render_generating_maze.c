/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** render_generating_maze
*/

#include "my.h"
#include "src.h"
#include "struct_generator.h"

void render_generat_map(cell_t **cell, maze_t *maze)
{
    for (int i = 0; i < maze->nb_blocks; i++) {
        if (cell[i]->visited == true)
            maze->maze_map[cell[i]->pos_y][cell[i]->pos_x] = ' ';
    }
}