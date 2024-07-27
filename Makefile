NAME = push_swap

SOURCES = main.c sort_stack.c rotate_stack.c rev_rotate_stack.c \
		free_functions.c push_to_stack_b.c push_to_stack_a.c swap_functions.c \
		push_functions.c sort_utils.c validation_utils.c stack_prep.c \
		calculate_push_cost.c handle_args_input.c handle_string_input.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		$(CC) -c $(CFLAGS) $?

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

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
