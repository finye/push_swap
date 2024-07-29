/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args_input_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:01:49 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 12:02:30 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	validate_args_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]) == -1)
			error();
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			error();
		i++;
	}
}

void	parse_args_input(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b)
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
		handle_err_and_free(NULL, stack_a, stack_b);
	(*stack_a)->arr = malloc(sizeof(int) * (argc - 1));
	(*stack_b)->arr = malloc(sizeof(int) * (argc - 1));
	if (!(*stack_a)->arr || !(*stack_b)->arr)
		handle_err_and_free(NULL, stack_a, stack_b);
	init_stack_data(stack_a, argc -1);
	init_stack_data(stack_b, 0);
	while (i < argc)
		(*stack_a)->arr[j++] = ft_atoi(argv[i++]);
}

void	handle_args_input(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b)
{
	validate_args_input(argc, argv);
	parse_args_input(argc, argv, stack_a, stack_b);
	if (check_duplicate(stack_a) == -1)
		handle_err_and_free(NULL, stack_a, stack_b);
}
