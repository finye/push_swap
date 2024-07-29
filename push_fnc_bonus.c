/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fnc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:57:46 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 12:45:51 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (stack_b->size >= 1)
		ft_memmove(&stack_b->arr[0], &stack_b->arr[1],
			(stack_b->size) * sizeof(int));
	stack_a->size++;
	stack_b->size--;
}

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
	if (stack_a->size >= 1)
		ft_memmove(&stack_a->arr[0], &stack_a->arr[1],
			(stack_a->size) * sizeof(int));

	stack_b->size++;
	stack_a->size--;
}