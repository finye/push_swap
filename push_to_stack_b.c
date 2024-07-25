/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:19:23 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 17:50:28 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_target(int num_in_stack_a, t_stack *stack_b)
{
	int	i;
	int	target;
	int	closest_number;
	int	biggest;

	i = 0;
	target = -1;
	closest_number = INT_MIN;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] < num_in_stack_a \
			&& stack_b->arr[i] >= closest_number)
		{
			closest_number = stack_b->arr[i];
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

void	separate_pushes(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b)
{
	set_median(stack_a, stack_b);
	rotate_stack_a(ix_a, stack_a);
	rotate_stack_b(ix_b, stack_b);
}

void	push_to_target_b(int index_b, int index_a, t_stack *stack_a, t_stack *stack_b)
{
	int	median_b;
	int	i_b;
	int	median_a;
	int	i_a;

	i_b = stack_b->size - index_b;
	i_a = stack_a->size - index_a;
	median_b = stack_b->size / 2;
	median_a = stack_a->size / 2;
	if (index_b > median_b && index_a > median_a)
	{
		while (i_b > 0 && i_a > 0)
		{
			rrr(stack_a, stack_b);
			i_b--;
			i_a--;
		}
		while (i_b > 0)
		{
			rev_rotate(stack_b, 'b');
			i_b--;
		}
		while (i_a > 0)
		{
			rev_rotate(stack_a, 'a');
			i_a--;
		}
	}
	else if (index_b <= median_b && index_a <= median_a)
	{
		while (index_b > 0 && index_a > 0)
		{
			rr(stack_a, stack_b);
			index_b--;
			index_a--;
		}
		while (index_b > 0)
		{
			rotate(stack_b, 'b');
			index_b--;
		}
		while (index_a > 0)
		{
			rotate(stack_a, 'a');
			index_a--;
		}
	}
	else
		separate_pushes(index_a, index_b, stack_a, stack_b);
	push_into_b(stack_a, stack_b);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	index_b;
	int	index_a;

	while (stack_a->size > 3)
	{
		index_b = 0;
		index_a = 0;
		stack_a->cheapest = INT_MAX;
		while (index_a < stack_a->size)
		{
			if (stack_b->size <= 1)
			{
				push_into_b(stack_a, stack_b);
				break ;
			}
			else
			{
				index_b = check_target(stack_a->arr[index_a], stack_b);
				stack_a->push_cost = set_cost(index_b, stack_b, index_a, stack_a);
				if (stack_a->push_cost < stack_a->cheapest)
				{
					stack_a->cheapest = stack_a->push_cost;
					stack_a->cheapest_index = index_a;
					stack_a->target_index = index_b;
				}
			}
			index_a++;
		}
		if (stack_a->size > 3)
			push_to_target_b(stack_a->target_index, stack_a->cheapest_index, stack_a, stack_b);
	}
}