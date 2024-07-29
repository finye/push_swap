/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str_input_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:00:22 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 14:44:55 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_stack_data(t_stack **stack, int size)
{
	(*stack)->cheapest_index = 0;
	(*stack)->target_index = 0;
	(*stack)->push_cost = 0;
	(*stack)->cheapest = 0;
	(*stack)->size = size;
	(*stack)->median = (*stack)->size / 2;
}

void	allocate_stacks(char **split_str, t_stack **stack_a,
			t_stack **stack_b, int size)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_a || !*stack_b)
		handle_err_and_free(split_str, stack_a, stack_b);
	(*stack_a)->arr = malloc(sizeof(int) * size);
	(*stack_b)->arr = malloc(sizeof(int) * size);
	if (!(*stack_a)->arr || !(*stack_b)->arr)
		handle_err_and_free(split_str, stack_a, stack_b);
	init_stack_data(stack_a, size);
	init_stack_data(stack_b, 0);
}

void	validate_and_fill_stack_a(char **split_str, t_stack **stack_a,
			t_stack **stack_b)
{
	int	i;

	i = 0;
	while (split_str[i])
	{
		if (ft_atol(split_str[i]) > INT_MAX || ft_atol(split_str[i]) < INT_MIN)
			handle_err_and_free(split_str, stack_a, stack_b);
		(*stack_a)->arr[i] = ft_atoi(split_str[i]);
		i++;
	}
	if (check_duplicate(stack_a) == -1)
		handle_err_and_free(split_str, stack_a, stack_b);
}

void	handle_string_input(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**split_str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (argv[1][0] == '\0')
		return ;
	split_str = ft_split(argv[1], ' ');
	if (!split_str || !split_str[0])
	{
		free_split(split_str);
		return ;
	}
	while (split_str[i])
	{
		if (is_valid_num(split_str[i++]) == -1)
			handle_err_and_free(split_str, NULL, NULL);
		count++;
	}
	if (count > 0)
		allocate_stacks(split_str, stack_a, stack_b, count);
	validate_and_fill_stack_a(split_str, stack_a, stack_b);
	free_split(split_str);
}