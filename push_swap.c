/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 21:04:03 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <limits.h>


void	init_stack_data(t_stack **stack, int size)
{
	(*stack)->cheapest_index = 0;
	(*stack)->target_index = 0;
	(*stack)->push_cost = 0;
	(*stack)->cheapest = 0;
	(*stack)->size = size;
	(*stack)->median = (*stack)->size / 2;
}

void	parse_input(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	if (argc > 2)
	{
		*stack_a = malloc(sizeof(t_stack));
		*stack_b = malloc(sizeof(t_stack));
	}
	if (!*stack_a || !*stack_b)
		return ;
	(*stack_a)->arr = malloc(sizeof(int) * (argc - 1));
	(*stack_b)->arr = malloc(sizeof(int) * (argc - 1));
	if (!(*stack_a)->arr || !(*stack_b)->arr)
		return ;
	init_stack_data(stack_a, argc -1);
	init_stack_data(stack_b, 0);
	while (i < argc)
		(*stack_a)->arr[j++] = ft_atoi(argv[i++]);
}

void	handle_input(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b)
{
	validate_input(argc, argv);
	parse_input(argc, argv, stack_a, stack_b);
	if (check_duplicate(stack_a) == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		error();
	}
}

void	create_stack_a(char **argv, t_stack **stack_a, t_stack **stack_b)
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
		{
			free_split(input);
			error();
		}
		size++;
	}
	if (size > 0)
	{
		*stack_a = malloc(sizeof(t_stack));
		*stack_b = malloc(sizeof(t_stack));
	}
	//free input here too! TODO
	if (!*stack_a || !*stack_b)
		return ;
	(*stack_a)->arr = malloc(sizeof(int) * size);
	(*stack_b)->arr = malloc(sizeof(int) * size);
	if (!(*stack_a)->arr || !(*stack_b)->arr)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free_split(input);
		return ;
	}

	init_stack_data(stack_a, size);
	init_stack_data(stack_b, 0);
	i = 0;
	while (input[i])
	{
		if (atol(input[i]) > INT_MAX || atol(input[i]) < INT_MIN)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			free_split(input);
			error();
		}
		(*stack_a)->arr[i] = ft_atoi(input[i]);
		i++;
	}
	if (check_duplicate(stack_a) == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free_split(input);
		error();
	}
	if (input)
		free_split(input);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!argv || !*argv)
		error();
	if (argc == 2)
		create_stack_a(argv, &stack_a, &stack_b);
	else if (argc > 2)
		handle_input(argc, argv, &stack_a, &stack_b);
	if (stack_a && is_sorted(stack_a) == -1)
		sort_stack(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

