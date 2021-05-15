##
## EPITECH PROJECT, 2021
## Dante
## File description:
## Makefile
##

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -g

CPPFLAGS= 	-I../includes/

LDFLAGS = 	-L../lib/

LDLIBS 	= 	-lmy -lncurses

SRC 	= 	main.c										\
			error_handling.c 							\
			create_maze.c 								\
			fill_structs.c 	    						\
			free_generator.c 							\
			depth_first_search.c						\
			random.c 									\
			render_generator/render_generating_maze.c 	\
			render_generator/rendering.c				\

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	generator

all: 	$(NAME)
	@echo -e "\033[34mCompilation successful.\n\033[32m./$(NAME) created.\033[0m"

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug: 	CFLAGS += -g
debug: 	all

clean:
	$(RM) vgcore*
	$(RM) *~
	rm $(OBJ)

fclean: clean
	rm $(NAME)

run:
	./$(NAME)

.PHONY: all clean fclean