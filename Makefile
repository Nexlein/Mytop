##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell ls *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_top

CFLAGS	=	-W -Wall -Wextra -Werror -g3

LDFLAGS	=	-lncurses

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)  $(LDFLAGS)
	rm $(OBJ)

all:	$(NAME)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
