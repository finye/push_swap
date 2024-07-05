/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/05 17:13:18 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements
void sa(int **arr)  
{
    if (!arr || !*arr)
        return;
    int temp;
    temp = *arr[0];
    *arr[0] = *arr[1];
    *arr[1] = temp;
}
void create_stack_a(char *str)
{
    char **input;
    _stack *stack_a;
    int size;
    int i;

    size = 0;
    i = 0;
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
        stack_a = malloc(sizeof(_stack) * 1);
    if (!stack_a)
        return ;
    stack_a->arr = malloc(sizeof(int) * size);
    if (!stack_a->arr)
        return ;
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
        printf("%d = the stack BEFORE\n", stack_a->arr[j++]);
    }
    sa(&stack_a->arr);
   /*   j = 0;
    while(size--)
    {
        printf("%d = the stack \n", stack_a->arr[j++]);
    } */
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        create_stack_a(argv[1]);
    }
}


