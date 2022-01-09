##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	src/load_background.c			\
		src/create_structs.c			\
		src/game_loop.c					\
		src/my_runner.c					\
		src/parallax.c					\
		src/init.c

OBJ	=	$(SRC:.c=.o)

FLAGS =	-L./ -lgraphic -L./ -lmy -lcsfml-graphics -lcsfml-system

NAME	=	my_runner

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(MAKE) -C ./lib/graphic/
	gcc -o $(NAME) $(OBJ) $(FLAGS) 

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./lib/my/ clean
	$(MAKE) -C ./lib/graphic/ clean

fclean:
	rm -f $(NAME) $(OBJ)
	$(MAKE) -C ./lib/my/ fclean
	$(MAKE) -C ./lib/graphic/ fclean


re: fclean all
