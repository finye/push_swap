NAME = push_swap
BONUS_NAME = checker

SOURCES = main.c sort_stack.c rotate_stack.c rev_rotate_stack.c \
		free_functions.c push_to_stack_b.c push_to_stack_a.c swap_functions.c \
		push_functions.c sort_utils.c validation_utils.c stack_prep.c \
		calculate_push_cost.c handle_args_input.c handle_string_input.c

BONUS = checker_bonus.c swap_fnc_bonus.c rotate_stack_bonus.c rev_rot_stack_bonus.c \
		push_fnc_bonus.c handle_str_input_bonus.c handle_args_input_bonus.c \
		validation_utils_bonus.c free_fnc_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		$(CC) -c $(CFLAGS) $?

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS) $(LIBFT)
				$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
		make -C libft

clean:
		rm -f $(OBJECTS) $(BONUS_OBJECTS)
		make clean -C libft

fclean: clean
		rm -f $(NAME) $(BONUS_NAME)
		make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
