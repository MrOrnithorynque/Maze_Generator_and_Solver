/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** display_solved_maze
*/

#include "my.h"
#include "struct_solver.h"

static void print_maze(smaze_t *maze)
{
    for (int i = 0; maze->maze_map[i + 1] != NULL ; i++)
        printf("%s\n", maze->maze_map[i]);
    printf("%s", maze->maze_map[maze->lines - 1]);
}

static int get_cell_from_pos(int *pos, smaze_t *maze, int *vector)
{
    int cell = pos[0] + vector[0] + ((pos[1] + vector[1]) * maze->cols);

    if (pos[1] + vector[1] > maze->lines || pos[0] + vector[0] > maze->cols)
        return -1;

    return cell;
}

static int check_around(scell_t **cell, smaze_t *maze, int c)
{
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int vector[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int next_c = 0;

    for (int i = 0; i < 4; i++)
    {
        next_c = get_cell_from_pos(pos, maze, vector[i]);
        if (next_c >= 0 && next_c < maze->nb_blocks \
        && cell[next_c]->visited == true && cell[next_c]->path < cell[c]->path)
            return next_c;
    }

    return -1;
}

void create_finished_maze(scell_t **cell, smaze_t *maze)
{
    int c = maze->nb_blocks - 1;

    maze->maze_map[cell[c]->pos_y][cell[c]->pos_x] = 'o';
    while(c != 0)
    {
        if (check_around(cell, maze, c) != -1 && \
        check_around(cell, maze, c) < maze->nb_blocks)
        {
            c = check_around(cell, maze, c);
            maze->maze_map[cell[c]->pos_y][cell[c]->pos_x] = 'o';
        }
    }

    print_maze(maze);
}