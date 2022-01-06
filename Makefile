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
		lib/graphic/search_by_key.c		\
		src/create_structs.c			\
		src/init.c						\
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
	$(MAKE) -C ./lib/my/ clean

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
