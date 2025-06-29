NAME := small
CC := cc
CCFLAGS := -Wall -Wextra -Werror
AR := ar rcs
RM := rm -f

SRCS := main.c utility.c get_path.c command.c

OBJS := $(SRCS:.c=.o)

LIBFT_DIR := ../libft
LIBFT_A := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -I small.h -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all