/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:45 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 10:12:58 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of a stack.
//Do nothing if there is only one or no elements.
void	swap(t_stack *stack, char c)
{
	int	temp;

	if (!stack || !stack->arr || stack->size <= 1)
		return ;
	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
	if (c == 'a')
		write (1, "sa\n", 3);
	else if (c == 'b')
		write (1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
	write(1, "ss\n", 3);
}
