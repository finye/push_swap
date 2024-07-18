/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:01:32 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:49 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h> 

typedef struct _stack
{
    int *arr;
    int size;
    
} _stack;

//void create_stack_a(char *str);
void create_stack_a(int argc,char **argv, _stack *stack_a, _stack *stack_b);
void swap (_stack *stack_a, char c);
void ss (_stack *stack_a, _stack *stack_b);
void push_a(_stack *stack_a, _stack *stack_b);
void push_b(_stack *stack_a, _stack *stack_b);
void rotate(_stack *stack_a, char c);
void rr (_stack *stack_a, _stack *stack_b);
void rev_rotate(_stack *stack_a, char c);
void rrr(_stack *stack_a, _stack *stack_b);
void sort_me(_stack *stack_a, _stack *stack_b);
void min_sort(_stack *stack_a);
void sort_big(_stack *stack_a, _stack *stack_b);

#endif