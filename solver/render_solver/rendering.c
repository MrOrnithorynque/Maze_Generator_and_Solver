/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** rendering
*/

#include <ncurses.h>
#include "my.h"
#include "src.h"

static void print_map(smaze_t *maze)
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

static void manage_rendering(scell_t **cell, smaze_t *maze, srender_t *render)
{
    render_solved_map(cell, maze, render);
    print_map(maze);
}

void render_solver(scell_t **cell, smaze_t *maze, srender_t *render)
{
    int key = -1;
    WINDOW *screen = initscr();

    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while(key != 'q') {
        clear();
        manage_rendering(cell, maze, render);
        refresh();
        usleep(100000);
    }
    curs_set(TRUE);
    endwin();
}