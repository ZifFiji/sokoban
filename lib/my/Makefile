##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile for lib
##

SRC	=	my_str_to_word_array.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strndup.c	\
		my_getnbr.c	\
		my_strcmp.c	\
		my_show_tab.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf *~
	rm -rf *.log
	rm -rf #*#
	rm -rf .#*
	rm -rf '#*#'
	rm -rf libmy.a
	rm -rf *.out

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
