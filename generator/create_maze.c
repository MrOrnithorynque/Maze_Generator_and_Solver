/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** create_maze
*/

#include "my.h"
#include "struct_generator.h"
#include "src.h"

static char **create_end_maze(maze_t *maze)
{
    if (maze->cols % 2 == 0)
        maze->maze_map[maze->lines - 1][maze->cols - 1] = '*';
    if (maze->lines % 2 == 0)
        maze->maze_map[maze->lines - 1][maze->cols - 2] = '*';

    return maze->maze_map;
}

char **generate_fill_maze(int lines, int cols)
{
    int j = 0;
    int len = lines * cols + lines;
    char *str_map = malloc(sizeof(char) * (len + 1));
    char **array_map;

    for (int i = 0; i < len; i++) {
        if (j == cols) {
            str_map[i] = '\n';
            j = 0;
        }
        else {
            str_map[i] = 'X';
            j++;
        }
    }
    str_map[len] = '\0';
    array_map = my_str_to_array(str_map, "\n");
    free(str_map);

    return array_map;
}

char **generate_finished_maze(cell_t **cell, maze_t *maze)
{
    for (int i = 0; i < maze->nb_blocks; i++) {
        if (cell[i]->visited == true)
            maze->maze_map[cell[i]->pos_y][cell[i]->pos_x] = '*';
    }
    maze->maze_map = create_end_maze(maze);

    for (int i = 0; maze->maze_map[i + 1] != NULL ; i++)
        printf("%s\n", maze->maze_map[i]);
    printf("%s", maze->maze_map[maze->lines - 1]);

    return maze->maze_map;
}