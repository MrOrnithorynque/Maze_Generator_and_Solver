/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *str;

    if (stat(filepath, &sb) == -1) {
        my_puterror("error: no file found\n");
        return NULL;
    }
    str = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, str, sb.st_size);
    str[sb.st_size] = '\0';

    return str;
}