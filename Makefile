CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -D_POSIX_C_SOURCE=200809L
LDFLAGS =

NAME    = minishell
SRC     = main.c \
          shell.c \
          parser.c \
          executor.c \
          builtins.c \
          utils.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
