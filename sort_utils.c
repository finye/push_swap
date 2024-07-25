/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:03 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 17:18:08 by fsolomon         ###   ########.fr       */
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

int	separate_rot(int index_a, int index_b, t_stack *stack_a, t_stack *stack_b)
{
	int	total_cost;

	total_cost = 0;
	if (index_b <= stack_b->median)
		total_cost += index_b;
	else
		total_cost += stack_b->size - index_b;

	if (index_a <= stack_a->median)
		total_cost += index_a;
	else
		total_cost += stack_a->size - index_a;
	return (total_cost);
}
int	set_cost(int index_b, t_stack *stack_b, int index_a, t_stack *stack_a)
{
	int	total_cost;
	int	min_index;
	int	i_b;
	int	i_a;

	set_median(stack_a, stack_b);
	i_b = stack_b->size - index_b;
	i_a = stack_a->size - index_a;
	total_cost = 0;
	if (index_b <= stack_b->median && index_a <= stack_a->median)
	{
		min_index = index_b;
		if (index_a < index_b)
			min_index = index_a;
		total_cost += min_index;
		if (index_b > index_a)
			total_cost += (index_b - index_a);
		else
			total_cost += (index_a - index_b);
	}
	else if (index_b > stack_b->median && index_a > stack_a->median)
	{
		min_index = i_b;
		if (i_a < i_b)
			min_index = i_a;
		total_cost += min_index;
		if (i_b > i_a)
			total_cost += (i_b - i_a);
		else
			total_cost += (i_a - i_b);
	}
	else
		total_cost = separate_rot(index_a, index_b, stack_a, stack_b);
	return (total_cost);
}
