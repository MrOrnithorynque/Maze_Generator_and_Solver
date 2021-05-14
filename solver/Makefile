##
## EPITECH PROJECT, 2021
## Dante
## File description:
## Makefile
##

RM 		= 	rm -f

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -g

CPPFLAGS= 	-I../includes/

LDFLAGS = 	-L../lib/

LDLIBS 	= 	-lmy

SRC 	= 	main.c 					\
			error_handling.c		\
			fill_structs.c			\
			solver.c 				\
			display_solved_maze.c	\
			free_solver.c 			\

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	solver

all: $(NAME)
	@echo -e "\033[34mCompilation successful.\n\033[32m./$(NAME) created.\033[0m"

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug: 	CFLAGS += -g3
debug: 	re

clean:
	$(RM) vgcore*
	$(RM) *~
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

run:
	./$(NAME)

re: fclean all

.PHONY: all clean fclean