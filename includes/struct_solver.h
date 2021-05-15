/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>

typedef struct svector_s {
    int **vector;
} svector_t;

typedef struct smaze_s {
    int lines;
    int cols;
    int nb_blocks;
    char **maze_map;
} smaze_t;

typedef struct scell_s {
    int pos_x;
    int pos_y;
    int path;
    bool visited;
    bool tail;
    bool wall;
} scell_t;

typedef struct srender_s {
    int nb_blocks;
} srender_t;

#endif /* !STRUCT_H_ */
