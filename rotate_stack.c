/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:08:13 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 13:07:22 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one
void	rotate(t_stack *stack, char c)
{
	int	temp;

	if (!stack || !stack->arr || stack->size <= 1)
		return ;
	temp = stack->arr[0];
	ft_memmove(&stack->arr[0], &stack->arr[1], \
		(stack->size -1) * sizeof(int));
	stack->arr[stack->size - 1] = temp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

//rr : ra and rb at the same time.
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, '_');
	rotate(stack_b, '_');
	write(1, "rr\n", 3);
}
