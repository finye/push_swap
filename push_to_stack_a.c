/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:30:08 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 17:49:15 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_a(t_stack *stack_a, int num_in_stack_b)
{
	int	i;
	int	closest_bigger;
	int	target_index;

	i = 0;
	closest_bigger = INT_MAX;
	target_index = -1;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > num_in_stack_b
			&& stack_a->arr[i] <= closest_bigger)
		{
			closest_bigger = stack_a->arr[i];
			target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = find_smallest(stack_a);
	return (target_index);
}

void	rotate_stack_a(int index_a, t_stack *stack_a)
{
	int	rev_rotate_step;

	rev_rotate_step = stack_a->size - index_a;
	if (index_a > stack_a->median)
	{
		while (rev_rotate_step--)
			rev_rotate(stack_a, 'a');
	}
	else
	{
		while (index_a--)
			rotate(stack_a, 'a');
	}
}

void	rotate_stack_b(int index_b, t_stack *stack_b)
{
	int	rev_rotate_step;

	rev_rotate_step = stack_b->size - index_b;
	if (index_b > stack_b->median)
	{
		while (rev_rotate_step--)
			rev_rotate(stack_b, 'b');
	}
	else
	{
		while (index_b--)
			rotate(stack_b, 'b');
	}
}

void	prepare_to_push(int ix_a, t_stack *stack_a, int ix_b, t_stack *stack_b)
{
	set_median(stack_a, stack_b);
	rotate_stack_a(ix_a, stack_a);
	rotate_stack_b(ix_b, stack_b);
	push_into_a(stack_a, stack_b);
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;
	stack_b->cheapest = INT_MAX;
	while (index_b < stack_b->size)
	{
		index_a = find_target_in_a(stack_a, stack_b->arr[index_b]);
		stack_b->push_cost = set_cost(index_b, stack_b, index_a, stack_a);
		if (stack_b->push_cost < stack_b->cheapest)
		{
			stack_b->cheapest = stack_b->push_cost;
			stack_b->cheapest_index = index_b;
			stack_b->target_index = index_a;
		}
		index_b++;
	}
	prepare_to_push(stack_b->target_index, stack_a,
		stack_b->cheapest_index, stack_b);
}
