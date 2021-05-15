/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** fill_structs
*/

#include "my.h"
#include "src.h"
#include "struct_solver.h"

static scell_t *fill_cell_struct(void)
{
    scell_t *cell = malloc(sizeof(scell_t));

    cell->visited = false;
    cell->tail = false;
    cell->pos_x = 0;
    cell->pos_y = 0;
    cell->path = 0;
    cell->wall = false;

    return cell;
}

scell_t **cell_struct(smaze_t *maze)
{
    scell_t **cell = malloc(sizeof(scell_t) * maze->nb_blocks);
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
            (maze->maze_map[i][j] == 'X') ? cell[k]->wall = true : 0;
            k++;
        }
    }

    return cell;
}

smaze_t *maze_struct(char *map)
{
    smaze_t *maze = malloc(sizeof(smaze_t));

    for (int i = 0; map[i] != '\n'; i++, maze->cols++);
    for (int i = 0; map[i] != '\0'; i++)
    {
        if (map[i] == '\n')
            maze->lines++;
        if (map[i + 1] == '\0' && map[i] != '\n')
            maze->lines++;
    }
    maze->nb_blocks = maze->lines * maze->cols;
    maze->maze_map = my_str_to_array(map, "\n\0");

    return maze;
}

svector_t *vector_struct(void)
{
    svector_t *vect = malloc(sizeof(svector_t));
    int vector_ref[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    vect->vector = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 4; i++)
    {
        vect->vector[i] = malloc(sizeof(int) * 2);
        vect->vector[i][0] = vector_ref[i][0];
        vect->vector[i][1] = vector_ref[i][1];
    }

    return vect;
}

srender_t *render_struct(smaze_t *maze)
{
    srender_t *render = malloc(sizeof(srender_t));

    render->nb_blocks = maze->nb_blocks - 1;
    return render;
}