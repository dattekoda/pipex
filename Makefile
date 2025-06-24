NAME	:= pipex
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I includes
AR		:= ar rcs
RM		:= rm -f

SRC		:=

BONUS	:=

OBJ		:= $(SRC:.c=.o)
OBJ_BONUS	:= $(BONUS_:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
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