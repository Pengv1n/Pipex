NAME := pipex

LIBFT_DIR := libft
LIBFT_LIB := libft.a

MANDATORY_DIR := mandatory
BONUS_DIR := bonus

RM := rm -f

all:
		@make -C ${LIBFT_DIR}/ all