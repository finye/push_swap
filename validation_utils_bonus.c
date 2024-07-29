/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:04:57 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 15:05:29 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			i++;
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	handle_err_and_free(char **split_str, t_stack **stack_a,
			t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_split(split_str);
	error();
}
