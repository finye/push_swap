/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:28 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/16 12:24:50 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_sort(_stack *stack_a)
{
    printf("\n Min sorting \n");
    if (stack_a->arr[0] > stack_a->arr[1])
        swap(stack_a, 'a');
    if (stack_a->arr[1] > stack_a->arr[2])
        rev_rotate(stack_a, 'a');
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
int find_biggest(_stack *stack_b)
{
    int i;
    int max;
    int max_index;

    i = 0;
    max = -1;
    max_index = -1;
    while (i < stack_b->size)
    {
        if (stack_b->arr[i] > max)
        {
            max = stack_b->arr[i];
            max_index = i;
        }
        i++;
    }
    return (max_index);
}
int check_target(_stack *stack_a, _stack *stack_b)
{
    int i;
    int target;
    int closest_number;
    int biggest;

    i = 0;
    target = -1;
    closest_number = INT_MIN;

    while(i < stack_b->size)
    {
        if(stack_b->arr[i] < stack_a->arr[0] && stack_b->arr[i] > closest_number)
        {
           
            closest_number = stack_b->arr[i];
            target = i;
            printf("%d THE NUM TO PUSH \n", stack_a->arr[0]);
            printf("\n NEW target = %d\n", stack_b->arr[i]);
        }
        i++;
    }
    printf("THE target index = %d \n", target);
    //To do later! find the biggest number in stack_b
    if(target == -1)
    {
        biggest = find_biggest(stack_b);
        printf("THE biggest index = %d \n", biggest);
        printf("The biggest number = %d \n", stack_b->arr[biggest]);
        return(biggest);
    }
    
    return (target);
}
void push_to_target(int index, _stack *stack_a, _stack *stack_b)
{
    int median;
    int i;

    i = stack_b->size - index;
    median = stack_b->size / 2;
    if (index > median)
    {
        //rev_rotate until our guy is on top
        while(i--)
            rev_rotate(stack_b, 'b');
    }
    else if(index <= median)
    {
        while (index--)
            rotate(stack_b, 'b');
    }
    push_b(stack_a, stack_b);
}

void sort_big(_stack *stack_a, _stack *stack_b)
 {
    int index;
    index = 0;
    while(stack_a->size > 3)
    {
         printf("size_STACK_A = %d \n", stack_a->size);
         printf("size_STACK_B = %d \n", stack_b->size);
        //push_b(stack_a, stack_b);
        if (stack_b->size == 0)
            push_b(stack_a,stack_b);
        else if (stack_b->size == 1)
        {
            if(stack_a->arr[0] > stack_b->arr[0])
                push_b(stack_a, stack_b);
            else
            {
                push_b(stack_a, stack_b);
                rotate(stack_b, 'b');
            }      
        }
        else if (stack_b->size > 1)
        {
            //check_target(stack_a, stack_b);
            //printf("%d THE target index \n", check_target(stack_a, stack_b));
            index = check_target(stack_a, stack_b);
            push_to_target(index, stack_a, stack_b);
        }
    }
 }
void find_target(_stack *stack_a, _stack *stack_b)
{
    int i;
    int closest_bigger;
    int target_index;

    i = 0;
    closest_bigger = INT_MAX;
    target_index = -1;
    while(i < stack_a->size)
    {
        //if (stack_a->arr[i] > stack_b->arr[0] && )
        i++;
    }
}
void push_back_to_a(_stack *stack_a, _stack *stack_b)
{
    while(stack_b->size)
    {
        find_target(stack_a, stack_b);
    }
}
void sort_me(_stack *stack_a, _stack *stack_b)
{
    printf("Is sorted? %d \n",is_sorted(stack_a));
    if (is_sorted(stack_a) == 1)
        return ;
    if (stack_a->size > 3)
    {
         sort_big(stack_a, stack_b);
    }
    if (stack_a->size <= 3)
    {
         min_sort(stack_a);
    }
    push_back_to_a(stack_a, stack_b);
}
