NAME := pipex
CC := cc
CCFLAGS := -Wall -Wextra -Werror -I includes/pipex_bonus.h
RM := rm -f

SRCS := bonus/child_bonus.c bonus/error_bonus.c \
			bonus/free_bonus.c bonus/files_bonus.c \
			bonus/here_doc_bonus.c bonus/pipex_bonus.c

OBJS := $(SRCS:.c=.o)

LIBFT_DIR := ../libft
LIBFT_A := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all