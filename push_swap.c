/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/09 21:51:36 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<string.h>

int	ft_atoi(const char *str)
{
	int			sign;
	long int	number;
	long int	check;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		check = number;
		number = number * 10 + (*str - 48);
		if (number / 10 != check && sign > 0)
			return (-1);
		if (number / 10 != check && sign < 0)
			return (0);
		str++;
	}
	return (sign * number);
}
//Swap the first 2 elements at the top of a stack.
//Do nothing if there is only one or no elements.
void swap (_stack *stack_a)
{
    int temp;

    if (!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;
    temp = stack_a->arr[0];
    stack_a->arr[0] = stack_a->arr[1];
    stack_a->arr[1] = temp;
}
void ss (_stack *stack_a, _stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
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
    input = ft_split(str, ' ');
    while (input[i])
    {
        size++;
        printf("%s\n", input[i++]);
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
        stack_a->arr[i] = ft_atoi(input[i]);
        i++;
    }
    int j = 0;
    while(size--)
    {
        printf("%d th = %d stack_a __original \n", j, stack_a->arr[j]);
        j++;
    }
    printf("\n%d stack_a 0th __original\n", *(stack_a->arr));
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
    printf("%d stack_b  2th\n", *(stack_b->arr + 2));

}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        create_stack_a(argv[1]);
    }
}


