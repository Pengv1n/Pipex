NAME := pipex

LIBFT_DIR := libft
MANDATORY_DIR := mandatory
BONUS_DIR := bonus

RM := rm -f

all:
		make -C $(LIBFT_DIR)/ all
		make -C $(MANDATORY_DIR)/ all
		cp $(MANDATORY_DIR)/$(NAME) $(NAME)

bonus:
		make -C $(LIBFT_DIR)/ all
		make -C $(BONUS_DIR)/ all
		cp $(BONUS_DIR)/$(NAME) $(NAME)

clean:
		make -C $(LIBFT_DIR)/ clean
		make -C $(MANDATORY_DIR)/ clean
		make -C $(BONUS_DIR)/ clean

fclean:
		make -C $(LIBFT_DIR)/ fclean
		make -C $(MANDATORY_DIR)/ fclean
		make -C $(BONUS_DIR)/ fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re