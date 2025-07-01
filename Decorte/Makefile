NAME := pipex
CC := cc
CCFLAGS := -Wall -Wextra -Werror
RM := rm -f
INC := includes/pipex.h

SRCS := srcs/childs.c srcs/error.c \
		srcs/free.c srcs/pipex.c

OBJS := $(SRCS:.c=.o)

LIBFT_DIR := ../libft
LIBFT_A := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -I $(INC) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all