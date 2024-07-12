/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:28 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/12 18:21:09 by fsolomon         ###   ########.fr       */
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
int is_sorted(_stack *stack)
{
    int i;

    i = 0;
    while(i < stack->size - 1)
    {
        if(stack->arr[i] < stack->arr[i + 1])
            i++;
        else
            return(-1);
    }
    return (1);
}
 void sort_big(_stack *stack_a, _stack *stack_b)
 {
    while(stack_a->size > 3)
        push_b(stack_a, stack_b);
 }
void sort_me(_stack *stack_a, _stack *stack_b)
{
    printf("Is sorted? %d",is_sorted(stack_a));
    if (is_sorted(stack_a))
        return ;
    if (stack_a->size <= 3)
        min_sort(stack_a);
    else
         sort_big(stack_a, stack_b);

}