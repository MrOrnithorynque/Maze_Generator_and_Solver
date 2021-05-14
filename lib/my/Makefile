##
## EPITECH PROJECT, 2021
## Lib
## File description:
## Makefile for lib/my
##

INCLUDE		=	my.h

INCLUDE_PATH=	../../includes

RM 			=	rm -f

OBJ_PATH	=	obj/*

LIB			=	my_puterror.c 		\
				my_putstr.c			\
				my_swap.c			\
				my_strncmp.c		\
				my_strlen.c			\
				my_strcpy.c			\
				my_strcat.c			\
				my_revstr.c			\
				my_putnbr.c			\
				my_strcmp.c			\
				my_putchar.c		\
				my_strncpy.c		\
				my_get_float.c 		\
				my_getnbr.c			\
				my_strdup.c			\
				my_strstr.c			\
				modulo.c 			\
				my_str_to_array.c	\
				my_2d_to_3d.c 		\
				malloc_array.c 		\
				my_random.c 		\
				my_strndup.c 		\
				my_tablen.c 		\
				offset_array.c		\
				read_file.c 		\

OBJ 		= 	$(LIB:.c=.o)

NAME_LIB	= 	libmy.a

all: 	$(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	cp $(NAME_LIB) ../
	mv $(OBJ) obj
	cp $(INCLUDE) $(INCLUDE_PATH)

clean:
	$(RM) vgcore*
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME_LIB)
	cd .. && $(RM) $(NAME_LIB)

.PHONY: all clean fclean
