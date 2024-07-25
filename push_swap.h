/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:01:32 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/25 17:34:53 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	cheapest_index;
	int	target_index;
	int	push_cost;
	int	median;
	int	cheapest;
}	t_stack;

void	create_stack_a(char **argv, t_stack **stack_a, t_stack **stack_b);
void	handle_input(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b);
void	validate_input(int argc, char **argv);
int		check_duplicate(t_stack **stack_a);
int		is_valid_num(char *str);
void	error(void);
int		is_sorted(t_stack *stack);
void	swap(t_stack *stack_a, char c);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push_into_a(t_stack *stack_a, t_stack *stack_b);
void	push_into_b(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a, char c);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack_a, char c);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	min_sort(t_stack *stack_a);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack **stack);
void	free_split(char **input);
void	set_median(t_stack *stack_a, t_stack *stack_b);
int		find_smallest(t_stack *stack_a);
int		find_biggest(t_stack *stack_b);
void	set_median(t_stack *stack_a, t_stack *stack_b);
int		set_cost(int index_b, t_stack *stack_b, int index_a, t_stack *stack_a);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack_a(int index_a, t_stack *stack_a);
void	rotate_stack_b(int index_b, t_stack *stack_b);

#endif
