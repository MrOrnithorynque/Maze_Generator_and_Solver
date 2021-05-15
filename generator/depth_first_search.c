/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** depth_first_search
*/

#include <ncurses.h>
#include "my.h"
#include "src.h"
#include "struct_generator.h"

static int get_cell_from_pos(int *pos, maze_t *maze, int *vector)
{
    int cell = pos[0] + vector[0] + ((pos[1] + vector[1]) * maze->cols);

    if (pos[1] + vector[1] > maze->lines - 1 \
    || pos[0] + vector[0] > maze->cols - 1 \
    || pos[1] + vector[1] < 0 \
    || pos[0] + vector[0] < 0)
        return -1;

    return cell;
}

static int is_tail(cell_t **cell, maze_t *maze, int c)
{
    int vector[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int next_c = 0;

    for (int i = 0; i < 4; i++)
    {
        next_c = get_cell_from_pos(pos, maze, vector[i]);
        if (next_c < 0 && next_c >= maze->nb_blocks);
        else if (next_c >= 0 && next_c < maze->nb_blocks \
        && cell[next_c]->visited == false)
            return -1;
    }

    return 0;
}

static int check_around(cell_t **cell, maze_t *maze, int c)
{
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int vector[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, \
                        {1, -1}, {1, 1}, {-1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++)
    {
        c = get_cell_from_pos(pos, maze, vector[i]);
        if (c > 0 && c < maze->nb_blocks && cell[c]->visited == true)
            return -1;
    }

    return 0;
}

void detect_neighbors(cell_t **cell, maze_t *maze, int c)
{
    int pos[2] = {cell[c]->pos_x, cell[c]->pos_y};
    int next_c = 0;

    for (int i = 0; i < 4; i++)
    {
        next_c = get_cell_from_pos(pos, maze, cell[c]->vector[i]);
        if (next_c >= 0 && next_c < maze->nb_blocks && \
        cell[next_c]->visited == false && \
        check_around(cell, maze, next_c) == 0)
        {
            cell[next_c]->visited = true;
            cell[next_c]->tail = true;
            if (is_tail(cell, maze, c) == 0)
                cell[c]->tail = false;
            cell[get_cell_from_pos(pos, maze, cell[c]->min_vector[i])] \
            ->visited = true;
            render_generator(cell, maze);
            return;
        }
    }
}

void depth_first_search(cell_t **cell, maze_t *maze, int flag)
{
    int i_cell = 0;
    int key = -1;
    WINDOW *screen = initscr();

    curs_set(FALSE);
    keypad(stdscr, TRUE);
    for (int i = 0; i < maze->nb_blocks; i++) {
        for (int j = 0; j < maze->nb_blocks; j++) {
            if (cell[i_cell]->pos_x % 2 == 0 && \
            cell[i_cell]->pos_y % 2 == 0 && \
            cell[i_cell]->tail == true)
                detect_neighbors(cell, maze, i_cell);
            i_cell = j + rand() / (RAND_MAX / (maze->nb_blocks - j) + 1);
        }
    }
    if (flag == 0)
        for (int i = 0; i < maze->nb_blocks / 4; i++) {
            cell[i + rand() / (RAND_MAX / (maze->nb_blocks - i) + 1)]->visited\
            = true;
            render_generator(cell, maze);
        }
    generate_finished_maze(cell, maze);
    render_generator(cell, maze);
    curs_set(TRUE);
    endwin();
}