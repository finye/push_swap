/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fnc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:03:56 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 12:04:14 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
