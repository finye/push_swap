/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:28 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/11 16:26:49 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_sort(_stack *stack_a)
{

    if (stack_a->arr[0] > stack_a->arr[1])
        swap(stack_a, 'a');
    if (stack_a->arr[1] > stack_a->arr[2])
        rev_rotate(stack_a);
    if (stack_a->arr[0] > stack_a->arr[1])
        swap(stack_a, 'a');

}
void sort_me(_stack *stack_a)
{
    if (stack_a->size <= 3)
        min_sort(stack_a);
}