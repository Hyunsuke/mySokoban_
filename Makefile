##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## gcc
##

SRC	=	src/ncurses.c	\
		src/display_map.c	\
		src/keypad.c	\
		src/win_or_loose.c	\

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

LIB =	lib/my/libmy.a

LDLIBS = -lmy

LFLAGS = -L lib/my

CFLAGS =	-W -Wall -Wextra -g -lncurses -Iinclude

VALGRIND =	-ggdb3

all:	$(LIB) $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(LFLAGS) $(CFLAGS)

debug:	$(LIB)
	gcc -o $(NAME) $(SRC) $(LDLIBS) $(LFLAGS) $(CFLAGS) $(VALGRIND) -g

$(LIB):
	$(MAKE) -C lib/my/

clean:
	$(MAKE) -C lib/my/ clean
	rm -rf $(OBJ)

fclean:     clean
	$(MAKE) -C lib/my fclean
	rm -f $(NAME)


re: fclean all

.PHONY: all fclean clean re
