/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 00:46:57 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 12:49:01 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
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
void	free_stack(t_stack **stack);
void	free_split(char **split_str);
void	handle_err_and_free(char **split_str, t_stack **stack_a,
			t_stack **stack_b);
void	push_into_a(t_stack *stack_a, t_stack *stack_b);
void	push_into_b(t_stack *stack_a, t_stack *stack_b);

void	swap(t_stack *stack_a);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_a);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate(t_stack *stack_a);
void	rrr(t_stack *stack_a, t_stack *stack_b);
#endif
