##
## EPITECH PROJECT, 2020
## root
## File description:
## Main Makefile
##

all:	make_lib

make_lib:
	@make -sC lib/my
	@make -sC generator
	@make -sC solver

debug:
	@make debug -C solver

clean:
	@cd lib/my && make clean
	@cd generator/ && make clean
	@cd solver/ && make clean

fclean:
	@cd lib/my && make fclean
	@cd generator && make fclean
	@cd solver && make fclean

re: 	fclean all
	@cd lib/my && make clean
	@cd generator && make clean
	@cd solver && make clean

.PHONY: all clean fclean
