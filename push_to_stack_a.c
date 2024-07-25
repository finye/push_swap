/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:30:08 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 20:16:18 by fsolomon         ###   ########.fr       */
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

void	prepare_to_push(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b)
{
	int	rrr_steps_a;
	int	rrr_steps_b;

	rrr_steps_a = stack_a->size - ix_a;
	rrr_steps_b = stack_b->size - ix_b;

	set_median(stack_a, stack_b);
	if (ix_b > stack_b->median && ix_a > stack_a->median)
		rrr_actions(rrr_steps_a, rrr_steps_b, stack_a, stack_b);
	else if (ix_b <= stack_b->median && ix_a <= stack_a->median)
		rr_actions(ix_a, ix_b, stack_a, stack_b);
	else
		separate_rots(ix_a, ix_b, stack_a, stack_b);
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
	prepare_to_push(stack_b->target_index,
		stack_b->cheapest_index, stack_a, stack_b);
}
