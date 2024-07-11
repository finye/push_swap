NAME = push_swap

SOURCES = push_swap.c sort_me.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		$(CC) -c $(CFLAGS) $?

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) -g $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C libft

clean:
		rm -f $(OBJECTS)
		make clean -C libft

fclean: clean
		rm -f $(NAME)
		make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
