/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** struct_generator
*/

#ifndef STRUCT_GENERATOR_H_
#define STRUCT_GENERATOR_H_

#include <stdbool.h>

typedef struct maze_s {
    int lines;
    int cols;
    int nb_blocks;
    char **maze_map;
} maze_t;

typedef struct cell_s {
    int pos_x;
    int pos_y;
    bool tail;
    bool visited;
    bool *wall;
    int *neighbors;
    int **vector;
    int **min_vector;
} cell_t;

#endif /* !STRUCT_GENERATOR_H_ */
