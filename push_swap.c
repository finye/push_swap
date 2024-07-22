/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/22 11:44:25 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <limits.h>

int check_duplicate(_stack **stack_a)
{
    int i;
    int j;
    i = 0;

    if(!(*stack_a) || !(*stack_a)->size)
        return (-1);
    if ((*stack_a)->size == 1)
        return (1);
    while (i < (*stack_a)->size)
    {
        j = i + 1;
        while( j < (*stack_a)->size)
        {
            if ((*stack_a)->arr[i] == (*stack_a)->arr[j])
                return (-1);
            j++;
        }
        i++;
    }
    return (1);
}
void    error()
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
void is_num(char *str)
{
    int i;

    i = 0;

    if (str[0] == '\0')
        error();

    while(str[i])
    {
        if(i == 0 && str[i] == '-')
        {
            i++;
        }
        if (!(str[i] >= '0' && str[i] <= '9'))
            error();
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
void rotate(_stack *stack_a, char c)
{
    int temp;

    if(!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;
    temp = stack_a->arr[0];
    ft_memmove(&stack_a->arr[0], &stack_a->arr[1], (stack_a->size -1) * sizeof(int));
    stack_a->arr[stack_a->size - 1] = temp;
    if (c == 'a')
        write(1, "ra\n", 3);
    else if (c == 'b')
        write(1, "rb\n", 3);
}
//rr : ra and rb at the same time.
void rr (_stack *stack_a, _stack *stack_b)
{
    rotate(stack_a, 'a');
    rotate(stack_b, 'b');
    write(1, "rr\n", 3);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void rev_rotate(_stack *stack_a, char c)
{
    int temp;

    if (!stack_a || !stack_a->arr || stack_a->size <= 1)
        return ;

    temp = stack_a->arr[stack_a->size -1];
    ft_memmove(&stack_a->arr[1], &stack_a->arr[0], sizeof(int) * (stack_a->size -1));
    stack_a->arr[0] = temp;
    if (c == 'a')
        write(1, "rra\n", 4);
    else if (c == 'b')
        write(1, "rrb\n", 4);

}

//rrr : rra and rrb at the same time.
void rrr(_stack *stack_a, _stack *stack_b)
{
    rev_rotate(stack_a, 'a');
    rev_rotate(stack_b, 'b');
    write(1, "rrr\n", 4);
}

void free_stack(_stack **stack) {
    if (stack && *stack)
    {
        if ((*stack)->arr)
        {
            free((*stack)->arr);
            (*stack)->arr = NULL;
        }
        free(*stack);
        *stack = NULL;
    }
}

void validate_input(int argc, char **argv)
{
    int i;

    i = 1;
    while(i < argc)
    {
        is_num(argv[i]);
        if (atol(argv[i]) > INT_MAX || atol(argv[i]) < INT_MIN)
            error();
        i++;
    }
}
void init_stack_data(_stack **stack)
{
    (*stack)->cheapest_index = 0;
    (*stack)->target_index = 0;
    (*stack)->push_cost = 0;
    (*stack)->cheapest = 0;
    (*stack)->median = (*stack)->size / 2;
}
void parse_input(int argc,char **argv, _stack **stack_a,_stack **stack_b)
{
    int i;
    int j;

    i = 1;
    j = 0;

    if (argc > 2)
    {
        *stack_a = malloc(sizeof(_stack));
        *stack_b = malloc(sizeof(_stack));
    }
    if (!*stack_a || !*stack_b)
        return ;
    (*stack_a)->arr = malloc(sizeof(int) * (argc - 1));
    (*stack_b)->arr = malloc(sizeof(int) * (argc - 1));
    if (!(*stack_a)->arr || !(*stack_b)->arr)
        return ;
    (*stack_a)->size = argc -1;
    (*stack_b)->size = 0;
    init_stack_data(stack_a);
    init_stack_data(stack_b);
    while (i < argc)
    {
         (*stack_a)->arr[j++] = ft_atoi(argv[i++]);
    }
}
void handle_input(int argc, char **argv, _stack **stack_a, _stack **stack_b)
{
     validate_input(argc, argv);
     parse_input(argc, argv, stack_a, stack_b);
     if (check_duplicate(stack_a) == -1)
        {
            free_stack(stack_a);
            free_stack(stack_b);
            error();
        }
}
void create_stack_a(char **argv, _stack **stack_a, _stack **stack_b)
{
    char **input;
    int size;
    int i;

    size = 0;
    i = 0;

    if (!argv[1] || argv[1][0] == '\0')
        return ;
    input = ft_split(argv[1], ' ');
    if (!input)
        return ;
    while (input[i])
    {
        is_num(input[i++]);
        size++;
    }
    if (size > 0)
    {
        *stack_a = malloc(sizeof(_stack));
        *stack_b = malloc(sizeof(_stack));
    }

    if (!*stack_a || !*stack_b)
        return ;
    (*stack_a)->arr = malloc(sizeof(int) * size);
    (*stack_b)->arr = malloc(sizeof(int) * size);
    if (!(*stack_a)->arr || !(*stack_b)->arr)
    {
          free_stack(stack_a);
          free_stack(stack_b);
          return ;
    }

    (*stack_a)->size = size;
    (*stack_b)->size = 0;
    init_stack_data(stack_a);
    init_stack_data(stack_b);
    i = 0;
    while (input[i])
    {
        //printf("%s\n", input[i++]);
        if (atol(input[i]) > INT_MAX || atol(input[i]) < INT_MIN )
            {
                free_stack(stack_a);
                free_stack(stack_b);
                error();
            }
            (*stack_a)->arr[i] = ft_atoi(input[i]);
            i++;
    }
    //checking doubles
    //printf("%d = return from check_duplicate \n",check_duplicate(stack_a));
     if (check_duplicate(stack_a) == -1)
        {
            free_stack(stack_a);
            free_stack(stack_b);
            error();
        }
}

int main(int argc, char **argv)
{
    _stack *stack_a;
    _stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (1);
    if(!argv || !*argv)
        error();
    if (argc == 2)
        create_stack_a(argv, &stack_a, &stack_b);
   else if (argc > 2)
        handle_input(argc, argv, &stack_a, &stack_b);
    if(stack_a && is_sorted(stack_a) == -1)
        sort_stack(stack_a, stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}


