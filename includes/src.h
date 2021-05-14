/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** src
*/

#ifndef SRC_H_
#define SRC_H_

//--------------------------INCLUDES--------------------------

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include "struct_generator.h"
#include "struct_solver.h"

//---------------------------STATIC---------------------------

static const int UP[]       = {0, -2};
static const int DOWN[]     = {0, 2};
static const int LEFT[]     = {-2, 0};
static const int RIGHT[]    = {2, 0};

//----------------------------SRC-----------------------------

int     random_from_address(int address, int min, int max);
int     *create_random_cell(int nb_cells);
char    *read_file(char *filepath);
char    **generate_fill_maze(int lines, int cols);
char    **generate_finished_maze(cell_t **cell, maze_t *maze);
void    water_solver(scell_t **cell, smaze_t *maze, svector_t *vect);
void    depth_first_search(cell_t **cell, maze_t *maze, int flag);
void    error_handling_generation(int ac, char **av);
void    error_handling_solver(int ac, char **av);
void    free_generator(cell_t **cell, maze_t *maze);
void    free_solver(scell_t **cell, smaze_t *maze, svector_t *vect);
void    create_finished_maze(scell_t **cell, smaze_t *maze);
void    detect_neighbors(cell_t **cell, maze_t *maze, int c);
void    random_vector(cell_t *cell);
cell_t  **create_tab_cell_struct(maze_t *maze);
scell_t **cell_struct(smaze_t *maze);
maze_t  *fill_maze_struct(int lines, int cols);
smaze_t *maze_struct(char *map);
svector_t *vector_struct(void);

#endif /* !SRC_H_ */
