##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	lib/graphic/list.c				\
		lib/graphic/load_background.c	\
		lib/graphic/load_map.c			\
		lib/graphic/parallax.c			\
		src/create_structs.c			\
		src/game_loop.c					\
		src/my_runner.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(SRC) -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -g3

clear:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
