NAME := pipex

cc := gcc
FLAGS := -Wall -Werror -Wextra

LIBFT_DIR := ../libft
LIBFT := libft.a

GNL := ../get_next_line

HEAD := pipex.h
SRC := 	pipex.c	\
		parse.c \
		make_pipe.c \
		$(GNL)/get_next_line.c

OBJ := $(SRC:.c=.o)

INCLUDES := -I . -I $(GNL)

$(NAME):	$(OBJ) $(SRC)
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

