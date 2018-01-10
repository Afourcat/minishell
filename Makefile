##
## EPITECH PROJECT, 2017
## Makefile 
## File description:
## root makefile
##

DEB 	?=	0

NAME	=	mysh

all:	$(NAME)

$(NAME):
	@make --no-print-directory -C sources/ all

re:
	@make --no-print-directory -C sources/ re

debug:
	@make --no-print-directory -C sources/ re DEB=1

clean:
	@make --no-print-directory -C sources/ clean

fclean:
	@make --no-print-directory -C sources/ fclean

test_run:	$(NAME)
		@make --no-print-directory -C bonus/unittest/ all
		@make --no-print-directory fclean

.PHONY:	re	clean	fclean	test_run
