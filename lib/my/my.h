/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Louis's my.h
*/

#ifndef MY_H_

//--------------------------DEFINES---------------------------

#define MY_H_
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"
#define UNUSED __attribute__ ((unused))
#define CTOI(x) (x - 48)
#define ITOC(x) (x + 48)

//-------------------------INCLUDES---------------------------

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//----------------------------LIB-----------------------------

void    my_putchar(char c);
void    my_puterror(char *str);
void    my_putnbr(int nb);
void    my_putstr(char const *str);
void    my_swap(int *a, int *b);
int     my_random(int min, int max);
int     my_strcmp(char const *s1, char const *s2);
int     my_strlen(char const *str);
int     my_strncmp(char const *s1, char const *s2, int n);
int 	my_tablen(void **tab);
int     random_from_address(int address, int min, int max);
float   modulo(float x, float y);
float   my_get_float(char *str);
long    my_getnbr(char const *str);
char    *malloc_array(int cols);
char    *my_revstr(char *str);
char    *my_strcat(char *dest, char const *src);
char    *my_strcpy(char *dest, char const *src);
char    *my_strdup(char const *src);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strndup(char const *src, int n);
char    *my_strstr(char *str, char const *to_find);
char    *read_file(char *filepath);
char 	**offset_array(char **tab, size_t offset);
char    **my_str_to_array(char *str, char *parser);
char    **malloc_2d_array(int lines, int cols);
char    ***malloc_3d_array(int lines, int cols, int depth);
char    ***my_2d_to_3d(char **array, char *parser);

#endif /* !MY_H_ */
