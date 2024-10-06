##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile for my_sokoban
##

SRC	=	src/main.c	\
		src/sokoban.c	\
		src/initialize.c	\
		src/display.c	\
		src/result.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-Llib/my/ -lmy -Iinclude -lncurses

CFLAGS	=	-W -Wall -Wextra -Wpedantic

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C	lib/my/
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

debug: CFLAGS += -g
debug: $(NAME)

clean:
		rm -rf $(OBJ)
		rm -rf *~
		rm -rf #*#
		rm -rf '#*#'
		$(MAKE) -C lib/my/ clean
		rm -rf *.out
		rm -rf vgcore*

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C lib/my/ fclean

re: fclean all

.PHONY:	all clean fclean re debug
