/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/27 10:30:23 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!argv || !*argv)
		error();
	if (argc == 2)
		handle_string_input(argv, &stack_a, &stack_b);
	else if (argc > 2)
		handle_args_input(argc, argv, &stack_a, &stack_b);
	if (stack_a && is_sorted(stack_a) == -1)
		sort_stack(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
