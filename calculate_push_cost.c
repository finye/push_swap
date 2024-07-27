/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_push_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 09:39:29 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 22:35:06 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	calc_above_median_cost(int rrr_steps_a, int rrr_steps_b)
{
	int	cost;
	int	min_index;

	cost = 0;
	min_index = rrr_steps_b;
	if (rrr_steps_a < rrr_steps_b)
		min_index = rrr_steps_a;
	cost += min_index;
	if (rrr_steps_b > rrr_steps_a)
		cost += (rrr_steps_b - rrr_steps_a);
	else
		cost += (rrr_steps_a - rrr_steps_b);
	return (cost);
}

int	calc_below_median_cost(int index_a, int index_b)
{
	int	cost;
	int	min_index;

	cost = 0;
	min_index = index_b;
	if (index_a < index_b)
		min_index = index_a;
	cost += min_index;
	if (index_b > index_a)
		cost += (index_b - index_a);
	else
		cost += (index_a - index_b);
	return (cost);
}

int	set_cost(int index_b, t_stack *stack_b, int index_a, t_stack *stack_a)
{
	int	total_cost;
	int	rrr_steps_b;
	int	rrr_steps_a;

	set_median(stack_a, stack_b);
	rrr_steps_b = stack_b->size - index_b;
	rrr_steps_a = stack_a->size - index_a;
	total_cost = 0;
	if (index_b <= stack_b->median && index_a <= stack_a->median)
		total_cost += calc_below_median_cost(index_a, index_b);
	else if (index_b > stack_b->median && index_a > stack_a->median)
		total_cost += calc_above_median_cost(rrr_steps_a, rrr_steps_b);
	else
		total_cost = separate_rot(index_a, index_b, stack_a, stack_b);
	return (total_cost);
}
