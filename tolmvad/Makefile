NAME := pipex
CC := cc
CCFLAGS := -Wall -Wextra -Werror
RM := rm -f
INC := includes/pipex.h
BONUS_INC := includes/pipex_bonus.h

SRCS := srcs/childs.c srcs/error.c \
		srcs/free.c srcs/pipex.c

OBJS := $(SRCS:.c=.o)

BONUS_SRCS :=	bonus/childs_bonus.c bonus/error_bonus.c \
				bonus/free_bonus.c bonus/pipex_bonus.c

BONUS_OBJS :=	$(BONUS_SRCS:.c=.o)

LIBFT_DIR := ../libft
LIBFT_A := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -I $(INC) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(BONUS_OBJS) $(LIBFT_A) -I $(BONUS_INC) -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all