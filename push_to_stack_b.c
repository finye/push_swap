/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:19:23 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 22:48:27 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_in_b(int num_in_stack_a, t_stack *stack_b)
{
	int	i;
	int	target;
	int	closest_smaller;
	int	biggest;

	i = 0;
	target = -1;
	closest_smaller = INT_MIN;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] < num_in_stack_a
			&& stack_b->arr[i] >= closest_smaller)
		{
			closest_smaller = stack_b->arr[i];
			target = i;
		}
		i++;
	}
	if (target == -1)
	{
		biggest = find_biggest(stack_b);
		return (biggest);
	}
	return (target);
}

void	prep_to_push(int index_b, int index_a, t_stack *stack_a,
			t_stack *stack_b)
{
	int	rrr_steps_a;
	int	rrr_steps_b;

	rrr_steps_a = stack_a->size - index_a;
	rrr_steps_b = stack_b->size - index_b;
	set_median(stack_a, stack_b);
	if (index_b > stack_b->median && index_a > stack_a->median)
		rrr_actions(rrr_steps_a, rrr_steps_b, stack_a, stack_b);
	else if (index_b <= stack_b->median && index_a <= stack_a->median)
		rr_actions(index_a, index_b, stack_a, stack_b);
	else
		separate_rots(index_a, index_b, stack_a, stack_b);
	push_into_b(stack_a, stack_b);
}

void	find_cheapest_push(t_stack *stack_a, t_stack *stack_b)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	while (index_a < stack_a->size)
	{
		if (stack_b->size <= 1)
		{
			push_into_b(stack_a, stack_b);
			return ;
		}
		index_b = find_target_in_b(stack_a->arr[index_a], stack_b);
		stack_a->push_cost = set_cost(index_b, stack_b, index_a, stack_a);
		if (stack_a->push_cost < stack_a->cheapest)
		{
			stack_a->cheapest = stack_a->push_cost;
			stack_a->cheapest_index = index_a;
			stack_a->target_index = index_b;
		}
		index_a++;
	}
}

void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		stack_a->cheapest = INT_MAX;
		find_cheapest_push(stack_a, stack_b);
		if (stack_a->size > 3)
		{
			prep_to_push(stack_a->target_index, stack_a->cheapest_index,
				stack_a, stack_b);
		}
	}
}
