/*
** EPITECH PROJECT, 2021
** Maze_Generator_and_Solver
** File description:
** rendering
*/

#include <ncurses.h>
#include "my.h"
#include "src.h"

void render_solver(char **map)
{
    for (size_t i = 0; map[i] != NULL; ++i) {
        for (size_t j = 0; map[i][j] != '\0'; ++j) {
            mvprintw(1, 1, map[i][j]);
        }
    }
}