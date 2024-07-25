/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:08:13 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 11:13:46 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one
void	rotate(_stack *stack_a, char c)
{
	int	temp;

	if (!stack_a || !stack_a->arr || stack_a->size <= 1)
		return ;
	temp = stack_a->arr[0];
	ft_memmove(&stack_a->arr[0], &stack_a->arr[1], \
		(stack_a->size -1) * sizeof(int));
	stack_a->arr[stack_a->size - 1] = temp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

//rr : ra and rb at the same time.
void	rr(_stack *stack_a, _stack *stack_b)
{
	rotate(stack_a, '_');
	rotate(stack_b, '_');
	write(1, "rr\n", 3);
}
