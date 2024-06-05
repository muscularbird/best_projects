##
## EPITECH PROJECT, 2023
## this is makefile
## File description:
## this is makefile
##

SRC_CHN_LST	=	./chained_list/my_add_node.c\
				./chained_list/my_find_node.c\
				./chained_list/my_list_size.c\
				./chained_list/my_delete_nodes.c

SRC	=	free_my_word_array.c\
		my_array_size.c\
		my_open.c\
		my_str_to_word_array.c\
		my_strdup.c\
		my_strlen.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\

OBJ	=	$(SRC_CHN_LST:.c=.o)\
 		$(SRC:.c=.o)


NAME	=	libmy.a

CFLAGS	+=	-Wall -Wextra -O2


test	=	unit_tests.out

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	mkdir -p ../../include/lib
	cp ./include/my.h ../../include/lib/
	cp ./include/my_chn_lst.h ../../include/lib/

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f ../$(NAME)
	rm -f $(test)

re:	fclean all


.PHONY: all libmy.a clean fclean re
