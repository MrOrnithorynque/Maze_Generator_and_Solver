/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** random
*/

#include "my.h"
#include "struct_generator.h"
#include "src.h"

int *create_random_cell(int nb_cells)
{
    struct timeb *time = malloc(sizeof(time_t));
    int *random_cell = malloc(sizeof(int) * nb_cells);
    int tmp = 0;
    int random = 0;

    for (int i = 0; i < nb_cells; i++)
        random_cell[i] = i;

    ftime(time);
    srand(time->millitm);
    for (int i = 0; i < nb_cells; i++)
    {
        random = i + rand() / (RAND_MAX / (nb_cells - i) + 1);
        tmp = random_cell[random];
        random_cell[random] = random_cell[i];
        random_cell[i] = tmp;
    }

    return random_cell;
}

void random_vector(cell_t *cell)
{
    struct timeb *time = malloc(sizeof(time_t));
    int tmp_vect[2]     = {0, 0};
    int tmp_min_vect[2] = {0, 0};
    int random = 0;

    ftime(time);
    srand(time->millitm);
    for (int i = 0; i < 4; i++) {
        random = i + rand() / (RAND_MAX / (4 - i) + 1);
        tmp_vect[0] = cell->vector[random][0];
        tmp_vect[1] = cell->vector[random][1];
        tmp_min_vect[0] = cell->min_vector[random][0];
        tmp_min_vect[1] = cell->min_vector[random][1];
        cell->vector[random][0] = cell->vector[i][0];
        cell->vector[random][1] = cell->vector[i][1];
        cell->min_vector[random][0] = cell->min_vector[i][0];
        cell->min_vector[random][1] = cell->min_vector[i][1];
        cell->vector[i][0] = tmp_vect[0];
        cell->vector[i][1] = tmp_vect[1];
        cell->min_vector[i][0] = tmp_min_vect[0];
        cell->min_vector[i][1] = tmp_min_vect[1];
    }
}

int random_from_address(int address, int min, int max)
{
    int random = address / 10;

    (random < 0) ? random *= -1 : 0;
    random = min + (random % max);

    return random;
}