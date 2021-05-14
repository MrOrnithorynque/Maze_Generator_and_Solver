/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** fill_cell_struct
*/

#include "my.h"
#include "src.h"
#include "struct_generator.h"

static void vector_cell(cell_t *cell)
{
    int vector_ref[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    int min_vector_ref[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    cell->vector = malloc(sizeof(int *) * 4);
    cell->min_vector = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++)
    {
        cell->vector[i] = malloc(sizeof(int) * 2);
        cell->min_vector[i] = malloc(sizeof(int) * 2);
        cell->vector[i][0] = vector_ref[i][0];
        cell->vector[i][1] = vector_ref[i][1];
        cell->min_vector[i][0] = min_vector_ref[i][0];
        cell->min_vector[i][1] = min_vector_ref[i][1];
    }
}

static cell_t *fill_cell_struct(void)
{
    cell_t *cell = malloc(sizeof(cell_t));

    cell->visited = false;
    cell->tail = false;
    cell->pos_x = 0;
    cell->pos_y = 0;
    cell->neighbors = malloc(sizeof(int) * 4);
    cell->wall = malloc(sizeof(bool) * 4);
    for (int i = 0; i < 4; i++)
        cell->wall[i] = true;
    vector_cell(cell);
    random_vector(cell);

    return cell;
}

cell_t **create_tab_cell_struct(maze_t *maze)
{
    cell_t **cell = malloc(sizeof(cell_t) * maze->nb_blocks);
    int k = 0;

    for (int i = 0; i < maze->nb_blocks; i++)
        cell[i] = fill_cell_struct();

    cell[0]->visited = true;
    cell[0]->tail = true;
    for (int i = 0; i < maze->lines; i++)
    {
        for (int j = 0; j < maze->cols; j++)
        {
            cell[k]->pos_x = j;
            cell[k]->pos_y = i;
            k++;
        }
    }

    return cell;
}

maze_t *fill_maze_struct(int lines, int cols)
{
    maze_t *maze = malloc(sizeof(maze_t));

    maze->nb_blocks = lines * cols;
    maze->lines = lines;
    maze->cols = cols;
    maze->maze_map = generate_fill_maze(lines, cols);

    return maze;
}