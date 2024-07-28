/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:04:34 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/28 21:52:12 by fsolomon         ###   ########.fr       */
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

void	free_split(char **split_str)
{
	char	**temp;

	if (split_str)
	{
		temp = split_str;
		while (*split_str)
		{
			free(*split_str);
			split_str++;
		}
		free(temp);
	}
}
