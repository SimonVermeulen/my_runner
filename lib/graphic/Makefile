##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=   handle_events.c		\
		search_by_key.c		\
		load_legend.c		\
		load_map.c			\
		list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libgraphic.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../../
	cp graphic_lib.h ./../../include

clean:
	rm -f $(OBJ) $(NAME) ./../../$(NAME) ./include/graphic_lib.h 

fclean:
	rm -f $(NAME) ../../$(NAME) $(OBJ)

re: fclean all
