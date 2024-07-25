/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:11:57 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 20:14:11 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	separate_rots(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b)
{
	set_median(stack_a, stack_b);
	rotate_stack_a(ix_a, stack_a);
	rotate_stack_b(ix_b, stack_b);
}

void	rrr_actions(int rrr_steps_a, int rrr_steps_b,
			t_stack *stack_a, t_stack *stack_b)
{
	while (rrr_steps_a > 0 && rrr_steps_b > 0)
	{
		rrr(stack_a, stack_b);
		rrr_steps_a--;
		rrr_steps_b--;
	}
	while (rrr_steps_a > 0)
	{
		rev_rotate(stack_a, 'a');
		rrr_steps_a--;
	}
	while (rrr_steps_b > 0)
	{
		rev_rotate(stack_b, 'b');
		rrr_steps_b--;
	}
}

void	rr_actions(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b)
{
	while (ix_a > 0 && ix_b > 0)
	{
		rr(stack_a, stack_b);
		ix_a--;
		ix_b--;
	}
	while (ix_a > 0)
	{
		rotate(stack_a, 'a');
		ix_a--;
	}
	while (ix_b > 0)
	{
		rotate(stack_b, 'b');
		ix_b--;
	}
}