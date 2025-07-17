NAME	:= pipex
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I includes/
AR		:= ar rcs

LIBFT_DIR := libft/
LIBFT_A := $(LIBFT_DIR)libft.a

SRC		:=	srcs/main_bonus.c srcs/child_bonus.c \
			srcs/err_bonus.c srcs/free_bonus.c \
			srcs/init_bonus.c srcs/utils_bonus.c

OBJ_DIR	:=	./objs/
OBJ		:=	$(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p objs

$(OBJ_DIR)%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all