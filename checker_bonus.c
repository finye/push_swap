/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 00:32:38 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 17:27:01 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	execute_cmnd(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n") && (*a)->size > 0)
		swap(*a);
	else if (!ft_strcmp(line, "sb\n") && (*b)->size > 0)
		swap(*b);
	else if (!ft_strcmp(line, "ss\n") && (*a)->size > 0 && (*b)->size > 0)
		ss(*a, *b);
	else if (!ft_strcmp(line, "ra\n") && (*a)->size > 0)
		rotate(*a);
	else if (!ft_strcmp(line, "rb\n") && (*b)->size > 0)
		rotate(*b);
	else if (!ft_strcmp(line, "rr\n") && (*a)->size > 0 && (*b)->size > 0)
		rr(*a, *b);
	else if (!ft_strcmp(line, "rra\n") && (*a)->size > 0)
		rev_rotate(*a);
	else if (!ft_strcmp(line, "rrb\n") && (*b)->size > 0)
		rev_rotate(*b);
	else if (!ft_strcmp(line, "rrr\n") && (*a)->size > 0 && (*b)->size > 0)
		rrr(*a, *b);
	else if (!ft_strcmp(line, "pa\n") && (*b)->size > 0)
		push_into_a(*a, *b);
	else if (!ft_strcmp(line, "pb\n") && (*a)->size > 0)
		push_into_b(*a, *b);
	else
		return (-1);
	return (0);
}

static void	read_and_exec_cmds(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (line[0] == '\0' || ft_strcmp(line, "\n") == 0)
		{
			if (line)
				free(line);
			break ;
		}
		if (execute_cmnd(stack_a, stack_b, line) == -1)
		{
			if (line)
				free(line);
			free_stack(stack_a);
			free_stack(stack_b);
			error();
		}
		if (line)
			free(line); 
		line = get_next_line(0);
	}
}

static int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

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
	/* if (argc == 2)
		handle_string_input(argv, &stack_a, &stack_b); */
	else if (argc > 2)
		handle_args_input(argc, argv, &stack_a, &stack_b);
	read_and_exec_cmds(&stack_a, &stack_b);
	if (stack_a && is_sorted(stack_a) == 1 && (stack_b->size == 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
