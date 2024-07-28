/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:01:32 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/28 21:59:10 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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

void	handle_string_input(char **argv, t_stack **stack_a, t_stack **stack_b);
void	handle_args_input(int argc, char **argv,
			t_stack **stack_a, t_stack **stack_b);
void	init_stack_data(t_stack **stack, int size);
void	validate_args_input(int argc, char **argv);
int		check_duplicate(t_stack **stack_a);
int		is_valid_num(char *str);
void	error(void);
void	handle_err_and_free(char **split_str, t_stack **stack_a,
			t_stack **stack_b);
void	free_stack(t_stack **stack);
void	free_split(char **split_str);
int		is_sorted(t_stack *stack);
void	push_into_a(t_stack *stack_a, t_stack *stack_b);
void	push_into_b(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack_a, char c);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a, char c);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack_a, char c);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	set_median(t_stack *stack_a, t_stack *stack_b);
int		find_smallest(t_stack *stack_a);
int		find_biggest(t_stack *stack_b);
void	set_median(t_stack *stack_a, t_stack *stack_b);
void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);
int		set_cost(int index_b, t_stack *stack_b, int index_a, t_stack *stack_a);
void	rotate_stack_a(int index_a, t_stack *stack_a);
void	rotate_stack_b(int index_b, t_stack *stack_b);
void	rr_actions(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b);
void	rrr_actions(int rrr_steps_a, int rrr_steps_b, t_stack *stack_a,
			t_stack *stack_b);
void	separate_rots(int ix_a, int ix_b, t_stack *stack_a, t_stack *stack_b);

#endif
