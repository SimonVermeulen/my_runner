##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	src/create_structs.c			\
		src/init.c						\
		src/game_loop.c					\
		src/my_runner.c

OBJ	=	$(SRC:.c=.o)

FLAGS =	-L./ -lgraphic -L./ -lmy -lcsfml-graphics -lcsfml-system

NAME	=	my_runner

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(MAKE) -C ./lib/graphic/
	gcc -o $(NAME) $(OBJ) $(FLAGS) -g3

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./lib/my/ clean
	$(MAKE) -C ./lib/graphic/ clean

fclean:
	rm -f $(NAME) $(OBJ)
	$(MAKE) -C ./lib/my/ fclean
	$(MAKE) -C ./lib/graphic/ fclean


re: fclean all
