NAME	:= pipex
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
AR		:= ar rcs
RM		:= rm -f

SRC		:=	srcs/main.c

BONUS	:=

OBJ		:= $(SRC:.c=.o)
OBJ_BONUS	:= $(BONUS_:.c=.o)

LIBFT_DIR := libft
LIBFT_A := libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(AR) $@ $^

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all