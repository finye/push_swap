/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:10:17 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 22:37:21 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_data(t_stack **stack, int size)
{
	(*stack)->cheapest_index = 0;
	(*stack)->target_index = 0;
	(*stack)->push_cost = 0;
	(*stack)->cheapest = 0;
	(*stack)->size = size;
	(*stack)->median = (*stack)->size / 2;
}

void	allocate_stacks(char **input, t_stack **stack_a,
			t_stack **stack_b, int size)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_a || !*stack_b)
		handle_err_and_free(input, stack_a, stack_b);
	(*stack_a)->arr = malloc(sizeof(int) * size);
	(*stack_b)->arr = malloc(sizeof(int) * size);
	if (!(*stack_a)->arr || !(*stack_b)->arr)
		handle_err_and_free(input, stack_a, stack_b);
	init_stack_data(stack_a, size);
	init_stack_data(stack_b, 0);
}

void	validate_and_fill_stack_a(char **input, t_stack **stack_a,
			t_stack **stack_b)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_atol(input[i]) > INT_MAX || ft_atol(input[i]) < INT_MIN)
			handle_err_and_free(input, stack_a, stack_b);
		(*stack_a)->arr[i] = ft_atoi(input[i]);
		i++;
	}
	if (check_duplicate(stack_a) == -1)
		handle_err_and_free(input, stack_a, stack_b);
}

void	handle_string_input(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**input;
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (!argv[1] || argv[1][0] == '\0')
		return ;
	input = ft_split(argv[1], ' ');
	if (!input)
		return ;
	while (input[i])
	{
		if (is_valid_num(input[i++]) == -1)
			handle_err_and_free(input, NULL, NULL);
		size++;
	}
	if (size > 0)
		allocate_stacks(input, stack_a, stack_b, size);
	validate_and_fill_stack_a(input, stack_a, stack_b);
	free_split(input);
}
