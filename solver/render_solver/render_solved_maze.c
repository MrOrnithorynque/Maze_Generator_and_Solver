/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** render_solved_maze
*/

#include "my.h"
#include "src.h"
#include "struct_solver.h"

static int check_around(scell_t **cell, smaze_t *maze, int c)
{
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int vector[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int next_c = 0;

    for (int i = 0; i < 4; ++i)
    {
        next_c = get_scell_from_pos(pos, maze, vector[i]);
        if (next_c >= 0 && next_c < maze->nb_blocks \
        && cell[next_c]->visited == true && cell[next_c]->path < cell[c]->path)
            return next_c;
    }

    return -1;
}

void render_solved_map(scell_t **cell, smaze_t *maze, srender_t *render)
{
    if (check_around(cell, maze, render->nb_blocks) != -1 && \
        check_around(cell, maze, render->nb_blocks) < maze->nb_blocks) {
        render->nb_blocks = check_around(cell, maze, render->nb_blocks);
        maze->maze_map[cell[render->nb_blocks]->pos_y][cell[render->nb_blocks]->pos_x] = 'o';
    }
}