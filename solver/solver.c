/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** solver
*/

#include "my.h"
#include "struct_solver.h"
#include "src.h"

static int is_finished(int solution, smaze_t *maze)
{
    static int tmp = 0;

    if (maze->maze_map[maze->lines - 1][maze->cols - 1] == 'X')
        return -1;
    else if (solution == tmp)
        return -1;
    else
        tmp = solution;

    return 0;
}

static int get_cell_from_pos(int *pos, smaze_t *maze, int *vector)
{
    int cell = pos[0] + vector[0] + ((pos[1] + vector[1]) * maze->cols);

    if (pos[1] + vector[1] > maze->lines - 1 \
    || pos[0] + vector[0] > maze->cols - 1 \
    || pos[1] + vector[1] < 0 \
    || pos[0] + vector[0] < 0)
        return -1;

    return cell;
}

static int is_neighbors(scell_t **cell, smaze_t *maze, svector_t *vect, int c)
{
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int next_c = 0;
    static int solution = 0;

    for (int i = 0; i < 4; i++)
    {
        next_c = get_cell_from_pos(pos, maze, vect->vector[i]);
        if (next_c >= 0 && next_c < maze->nb_blocks)
            if (cell[next_c]->visited == false && cell[next_c]->wall == false)
            {
                cell[next_c]->visited = true;
                cell[next_c]->tail = true;
                cell[next_c]->path = cell[c]->path + 1;
                cell[c]->tail = false;
                solution++;
            }
    }

    return solution;
}

void water_solver(scell_t **cell, smaze_t *maze, svector_t *vect)
{
    int solution = 1;

    while (cell[maze->nb_blocks - 1]->visited != true) {
        for (int i = 0; i < maze->nb_blocks; i++) {
            if (cell[i]->tail == true)
            {
                solution = is_neighbors(cell, maze, vect, i);
            }
        }
        if(is_finished(solution, maze) == -1)
        {
            my_putstr("no solution found");
            return;
        }
    }

    create_finished_maze(cell, maze);
}