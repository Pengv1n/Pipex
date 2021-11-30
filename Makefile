NAME := pipex

cc := gcc
FLAGS := -Wall -Werror -Wextra

LIBFT_DIR := libft
LIBFT := libft.a

HEAD := pipex.h
SRC := 	pipex.c	\
		parse.c

OBJ := $(SRC:.c=.o)

INCLUDES := -I .

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT_DIR)/$(LIBFT)

.o:		.c $(HEAD) Makefile
			$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

all:	$(NAME)

clean:
		rm -f $(OBJ)
fclean:	clean
		rm -f $(NAME)

re:
		fclean all

.PHONY: all clean fclean re

test:
	./$(NAME) a "grep a" "wc -c" b

