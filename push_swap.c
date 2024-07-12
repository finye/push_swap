/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/12 16:20:24 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<string.h>
#include <limits.h>

int check_duplicate(_stack *stack_a)
{
    int i;
    int j;
    i = 0;

    if(!stack_a || !stack_a->size)
        return (-1);
    if (stack_a->size == 1)
        return (1);
    while (i < stack_a->size)
    {
        j = i + 1;
        while( j < stack_a->size)
        {
            if (stack_a->arr[i] == stack_a->arr[j])
                return (-1);
            j++;
        }
        i++;
    }
    return (1);
}
void is_num(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(i == 0 && str[i] == '-')
        {
            i++;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))
            {
            write (1, "Error\n", 6);
            exit(1);
            }
        i++;
    }
}
//Swap the first 2 elements at the top of a stack.
//Do nothing if there is only one or no elements.
void swap (_stack *stack_a, char c)
{
    int temp;

    if (!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;
    temp = stack_a->arr[0];
    stack_a->arr[0] = stack_a->arr[1];
    stack_a->arr[1] = temp;
    if(c == 'a')
        write(1, "sa\n", 3);
    else if(c =='b')
        write(1, "sb\n", 3);
}
void ss (_stack *stack_a, _stack *stack_b)
{
    swap(stack_a, 'a');
    swap(stack_b, 'b');
    write(1, "ss\n", 3);
}
//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void push_a(_stack *stack_a, _stack *stack_b)
{
    int temp;
    if(!stack_b || !stack_b->arr || !stack_b->size)
        return ;
    temp = stack_b->arr[0];
    if(stack_a->size >= 1)
        ft_memmove(&stack_a->arr[1], &stack_a->arr[0], (stack_a->size) * sizeof(int));
    stack_a->arr[0] = temp;
    if(stack_b->size >=1)
        ft_memmove(&stack_b->arr[0], &stack_b->arr[1], (stack_b->size) * sizeof(int));

    stack_a->size++;
    stack_b->size--;
    write(1, "pa\n", 3);
}
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty
void push_b(_stack *stack_a, _stack *stack_b)
{
    int temp;
    if(!stack_a || !stack_a->arr || !stack_a->size)
        return ;
    temp = stack_a->arr[0];
/*     if(stack_b->size == 1)
        memmove(&stack_b->arr[1], &stack_b->arr[0], sizeof(int)); */
    if(stack_b->size >= 1)
        ft_memmove(&stack_b->arr[1], &stack_b->arr[0], (stack_b->size) * sizeof(int));
    stack_b->arr[0] = temp;
    if(stack_a->size >=1)
        ft_memmove(&stack_a->arr[0], &stack_a->arr[1], (stack_a->size) * sizeof(int));

    stack_b->size++;
    stack_a->size--;
    write(1, "pb\n", 3);
}
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one
void rotate(_stack *stack_a)
{
    int temp;

    if(!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;
    temp = stack_a->arr[0];
    ft_memmove(&stack_a->arr[0], &stack_a->arr[1], (stack_a->size -1) * sizeof(int));
    stack_a->arr[stack_a->size - 1] = temp;

}
//rr : ra and rb at the same time.
void rr (_stack *stack_a, _stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void rev_rotate(_stack *stack_a)
{
    int temp;

    if (!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;

    temp = stack_a->arr[stack_a->size -1];
    ft_memmove(&stack_a->arr[1], &stack_a->arr[0], sizeof(int) * (stack_a->size -1));
    stack_a->arr[0] = temp;

}

//rrr : rra and rrb at the same time.
void rrr(_stack *stack_a, _stack *stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
}
void free_stack(_stack *stack)
{
    if(stack->arr)
        free(stack->arr);
    free(stack);
}
void create_stack_a(char *str)
{
    char **input;
    _stack *stack_a;
    _stack *stack_b;
    int size;
    int i;

    size = 0;
    i = 0;
    stack_a = NULL;
    stack_b = NULL;
    if (!str)
        return ;
    /* while (str[i])
    {
        if(is_num(&str[i]) == -1)
        {
            write (1, "Error\n", 6);
            exit(1);
        }
    } */
    input = ft_split(str, ' ');
    while (input[i])
    {
        is_num(input[i++]);
        size++;
        //printf("%s\n", input[i++]);
    }
    printf("%d = The size \n\n", size);
    if(size)
    {
        stack_a = malloc(sizeof(_stack) * 1);
        stack_b = malloc(sizeof(_stack) * 1);
    }

    if (!stack_a || !stack_b)
        return ;
    stack_a->arr = malloc(sizeof(int) * size);
    stack_b->arr = malloc(sizeof(int) * size);
    if (!stack_a->arr || !stack_b->arr)
        return ;
    stack_a->size = size;
    stack_b->size = 0;
    i = 0;
    while (input[i])
    {
        //printf("%s\n", input[i++]);
        if (atol(input[i]) > INT_MAX || atol(input[i]) < INT_MIN )
            {
                write(1, "Error\n", 6);
                free(stack_a);
                free(stack_b);
                return ;
            }
            stack_a->arr[i] = ft_atoi(input[i]);
            i++;
    }
    //checking doubles
    printf("%d = return from check_duplicate \n",check_duplicate(stack_a));
    if (check_duplicate(stack_a) == -1)
        {
            write(1, "Error\n", 6);
            free_stack(stack_a);
            free(stack_b);
            return ;
        }
    int j = 0;
    while(size--)
    {
        printf("%d th = %d stack_a __original \n", j, stack_a->arr[j]);
        j++;
    } 
    /* printf("\n%d stack_a 0th __original\n", *(stack_a->arr));
    printf("%d stack_a 1th __original\n", *(stack_a->arr + 1));
    printf("%d stack_a 2th __original\n", *(stack_a->arr + 2));

    printf("\n%d stack_b 0th __original\n", *(stack_b->arr));
    printf("%d stack_b 1th __original\n", *(stack_b->arr + 1));
    printf("%d stack_b 2th __original\n", *(stack_b->arr + 2));

    //swap (stack_a);
    //rev_rotate(stack_a);
    printf("\n%d =size_A %d =size_B ___0\n", stack_a->size, stack_b->size);
    push_b(stack_a, stack_b);
    printf("%d =size_A %d =size_B ___1\n", stack_a->size, stack_b->size);
    push_b(stack_a, stack_b);
    printf("%d =size_A %d =size_B ___2\n", stack_a->size, stack_b->size);
    push_b(stack_a, stack_b);
    printf("%d =size_A %d =size_B ___3\n", stack_a->size, stack_b->size);
    push_b(stack_a, stack_b);
    printf("%d =size_A %d =size_B ___4\n", stack_a->size, stack_b->size);

    push_a(stack_a, stack_b);
    printf("%d =size_A %d =size_B __after push_a\n", stack_a->size, stack_b->size);
    push_a(stack_a, stack_b);
    printf("%d =size_A %d =size_B __after push_a\n", stack_a->size, stack_b->size);


    printf("\n%d stack_a 0th \n", *(stack_a->arr));
    printf("%d stack_a 1th\n", *(stack_a->arr + 1));
    printf("%d stack_a 2th\n", *(stack_a->arr + 2));

    printf("\n%d stack_b 0th\n", *(stack_b->arr));
    printf("%d stack_b 1th\n", *(stack_b->arr + 1));
    printf("%d stack_b  2th\n", *(stack_b->arr + 2)); */
    sort_me(stack_a, stack_b);
    printf("\n%d stack_a 0th\n", *(stack_a->arr));
    printf("%d stack_a 1th\n", *(stack_a->arr + 1));
    printf("%d stack_a  2th\n", *(stack_a->arr + 2));

    printf("\n%d stack_b 0th\n", *(stack_b->arr));
    printf("%d stack_b 1th\n", *(stack_b->arr + 1));
    printf("%d stack_b  2th\n", *(stack_b->arr + 2));
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        create_stack_a(argv[1]);
    }
}


