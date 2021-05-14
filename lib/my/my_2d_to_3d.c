/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** my_2d_to_3d
*/

#include "my.h"

struct data_array_t {
    int lines;
    int cols;
    int depth;
};

static int count_lines(char **array, char *parser)
{
    int lines = 0;

    for (size_t i = 0; array[i] != NULL; i++)
        if (my_strcmp(array[i], parser) != 0)
            ++lines;
    return lines;
}

static int count_cols(char **array)
{
    int cols = 0;
    int tmp = 0;

    for (size_t i = 0; array[i] != NULL; ++i) {
        for (int j = 0; array[i][j] != '\0'; ++j)
            ++tmp;
        (tmp > cols) ? cols = tmp : 0;
        tmp = 0;
    }
    return cols;
}

static int count_depth(char **array, char *parser)
{
    int depth = 1;

    for (size_t i = 0; array[i] != NULL; ++i)
        if (my_strcmp(array[i], parser) == 0 && array[i + 1] != NULL)
            depth++;
    return depth;
}

static char ***parser_array (char ***array, char **array_src, char *parser, \
                            struct data_array_t data_array)
{
    size_t k = 0;

    for (int i = 0; i < data_array.depth; ++i) {
        for (size_t j = 0; array_src[k] != NULL; ++j) {
            array[i][j] = my_strdup(array_src[k]);
            if (array_src[k + 1] == NULL \
            || my_strcmp(array_src[k + 1], parser) == 0) {
                array[i][j + 1] = NULL;
                k += 2;
                break;
            }
            ++k;
        }
    }
    array[data_array.depth] = NULL;
    return array;
}

char ***my_2d_to_3d(char **array, char *parser)
{
    struct data_array_t data_array;
    data_array.lines    = count_lines(array, parser);
    data_array.cols     = count_cols(array);
    data_array.depth    = count_depth(array, parser);
    char ***d3_array = malloc_3d_array \
    (data_array.lines, data_array.cols, data_array.depth);

    return parser_array(d3_array, array, parser, data_array);
}