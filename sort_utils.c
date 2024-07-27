/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:03 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 09:42:26 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack_a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = stack_a->arr[0];
	min_index = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < min)
		{
			min = stack_a->arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_biggest(t_stack *stack_b)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = stack_b->arr[0];
	max_index = 0;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] > max)
		{
			max = stack_b->arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

void	set_median(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->median = stack_a->size / 2;
	stack_b->median = stack_b->size / 2;
}
