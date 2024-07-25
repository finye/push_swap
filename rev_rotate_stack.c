/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:16:04 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 20:17:29 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	rev_rotate(t_stack *stack, char c)
{
	int	temp;

	if (!stack || !stack->arr || stack->size <= 1)
		return ;
	temp = stack->arr[stack->size -1];
	ft_memmove(&stack->arr[1], &stack->arr[0], sizeof(int) * (stack->size -1));
	stack->arr[0] = temp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

//rrr : rra and rrb at the same time.
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a, '_');
	rev_rotate(stack_b, '_');
	write(1, "rrr\n", 4);
}
