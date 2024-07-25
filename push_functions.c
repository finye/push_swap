/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:43:25 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 16:22:12 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	push_into_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!stack_b || !stack_b->arr || !stack_b->size)
		return ;
	temp = stack_b->arr[0];
	if (stack_a->size >= 1)
		ft_memmove(&stack_a->arr[1], &stack_a->arr[0],
			(stack_a->size) * sizeof(int));
	stack_a->arr[0] = temp;
	if (stack_b->size >=1)
		ft_memmove(&stack_b->arr[0], &stack_b->arr[1],
			(stack_b->size) * sizeof(int));
	stack_a->size++;
	stack_b->size--;
	write(1, "pa\n", 3);
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty
void	push_into_b(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!stack_a || !stack_a->arr || !stack_a->size)
		return ;
	temp = stack_a->arr[0];
	if (stack_b->size >= 1)
		ft_memmove(&stack_b->arr[1], &stack_b->arr[0],
			(stack_b->size) * sizeof(int));
	stack_b->arr[0] = temp;
	if (stack_a->size >=1)
		ft_memmove(&stack_a->arr[0], &stack_a->arr[1],
			(stack_a->size) * sizeof(int));

	stack_b->size++;
	stack_a->size--;
	write(1, "pb\n", 3);
}