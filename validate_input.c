/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:53:21 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 13:12:16 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	if (!(*stack_a) || !(*stack_a)->size)
		return (-1);
	if ((*stack_a)->size == 1)
		return (1);
	while (i < (*stack_a)->size)
	{
		j = i + 1;
		while (j < (*stack_a)->size)
		{
			if ((*stack_a)->arr[i] == (*stack_a)->arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
		}
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

void	validate_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]) == -1)
			error();
		if (atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
			error();
		i++;
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
