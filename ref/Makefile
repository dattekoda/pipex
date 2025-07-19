NAME	:= pipex
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I includes
CFLAGS_BONUS	:= -Wall -Wextra -Werror -I includes_bonus
AR		:= ar rcs

LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a

SRCS	:=	srcs/pipex.c srcs/utils.c \
			srcs/err.c srcs/free.c \
			srcs/main.c srcs/set.c

BONUS	:=	bonus/pipex_bonus.c bonus/child_bonus.c \
			bonus/err_bonus.c bonus/free_bonus.c \
			bonus/init_bonus.c bonus/init_utils_bonus.c \
			bonus/utils_bonus.c bonus/main_bonus.c

OBJ_DIR	:=	objs
OBJ		:=	$(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS))

BONUS_OBJ_DIR	:= objs_bonus
BONUS_OBJ		:= $(patsubst bonus/%.c,$(BONUS_OBJ_DIR)/%.o,$(BONUS))

.PHONY: all clean fclean re

all: $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS_BONUS) $^ -o $(NAME)


$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p objs

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR):
	mkdir -p objs_bonus

$(BONUS_OBJ_DIR)/%.o: bonus/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)


clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all