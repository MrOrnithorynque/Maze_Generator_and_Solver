/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** rendering
*/

#include <ncurses.h>
#include "my.h"
#include "src.h"
#include "struct_generator.h"

static void print_map(maze_t *maze)
{
    if (LINES < maze->lines || COLS < maze->cols) {
        mvprintw(LINES / 2, COLS / 2 - 9, "Terminal too small");
        return;
    }
    for (size_t i = 0; maze->maze_map[i] != NULL; ++i) {
        for (size_t j = 0; maze->maze_map[i][j] != '\0'; ++j) {
            mvprintw(LINES / 2 + i - maze->lines / 2,\
            COLS / 2 + j - maze->cols / 2, &maze->maze_map[i][j]);
        }
    }
}

void render_generator(cell_t **cell, maze_t *maze)
{
    clear();
    usleep(10000);
    render_generat_map(cell, maze);
    print_map(maze);
    refresh();
}