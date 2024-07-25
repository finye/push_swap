/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:04:34 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 12:05:35 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		if ((*stack)->arr)
		{
			free((*stack)->arr);
			(*stack)->arr = NULL;
		}
		free(*stack);
		*stack = NULL;
	}
}

void	free_split(char **input)
{
	char	**temp;

	if (input)
	{
		temp = input;
		while (*input)
		{
			free(*input);
			input++;
		}
		free(temp);
	}
}