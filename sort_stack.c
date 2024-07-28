/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:28 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/28 23:57:48 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if (stack_a->arr[0] > stack_a->arr[1])
		swap(stack_a, 'a');
	if (stack_a->arr[1] > stack_a->arr[2])
		rev_rotate(stack_a, 'a');
	if (stack_a->arr[0] > stack_a->arr[1])
		swap(stack_a, 'a');
}

void	final_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	rev_rotate_step;

	min_index = find_smallest(stack_a);
	set_median(stack_a, stack_b);
	if (min_index <= stack_a->median)
	{
		while (min_index--)
			rotate(stack_a, 'a');
	}
	else if (min_index > stack_a->median)
	{
		rev_rotate_step = stack_a->size - min_index;
		while (rev_rotate_step--)
			rev_rotate(stack_a, 'a');
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		push_to_stack_b(stack_a, stack_b);
	}
	if (stack_a->size <= 3)
	{
		sort_three(stack_a);
	}
	while (stack_b->size)
		push_back_to_a(stack_a, stack_b);
	if (is_sorted (stack_a) == -1)
		final_sort_a(stack_a, stack_b);
}
