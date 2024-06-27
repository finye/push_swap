/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:03:15 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/27 17:48:58 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_stack_a(char *str)
{
    char **stack;
    if (!str)
        return ;
    stack = ft_split(str, ' ');
    while (*stack)
    {
        printf("%s\n", *stack++);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        create_stack_a(argv[1]);
    }
}


