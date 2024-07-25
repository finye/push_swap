/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:28 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/24 23:43:08 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_sort(_stack *stack_a)
{
	if (stack_a->arr[0] > stack_a->arr[1])
		swap(stack_a, 'a');
	if ((is_sorted(stack_a) == -1) && stack_a->arr[1] > stack_a->arr[2])
		rev_rotate(stack_a, 'a');
	if ((is_sorted(stack_a) == -1) && stack_a->arr[0] > stack_a->arr[1])
		swap(stack_a, 'a');
}

int	is_sorted(_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

int	find_biggest(_stack *stack_b)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = stack_b->arr[0];
	max_index = 0;
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

int	check_target(int num_in_stack_a, _stack *stack_b)
{
	int	i;
	int	target;
	int	closest_number;
	int	biggest;

	i = 0;
	target = -1;
	closest_number = INT_MIN;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] < num_in_stack_a \
			&& stack_b->arr[i] >= closest_number)
		{
			closest_number = stack_b->arr[i];
			target = i;
		}
		i++;
	}
	if (target == -1)
	{
		biggest = find_biggest(stack_b);
		return (biggest);
	}
	return (target);
}

void	push_to_target_b_separ(int index_b, int index_a, _stack *stack_a, _stack *stack_b)
{
	int	median_b;
	int	i_b;
	int	median_a;
	int	i_a;

	i_b = stack_b->size - index_b;
	i_a = stack_a->size - index_a;
	median_b = stack_b->size / 2;
	median_a = stack_a->size / 2;
	if (index_b > median_b)
	{
		while (i_b--)
			rev_rotate(stack_b, 'b');
	}
	if (index_b <= median_b)
	{
		while (index_b--)
			rotate(stack_b, 'b');
	}
	if (index_a > median_a)
	{
		while (i_a--)
			rev_rotate(stack_a, 'a');
	}
	if (index_a <= median_a)
	{
		while (index_a--)
			rotate(stack_a, 'a');
	}
}

void	push_to_target_b(int index_b, int index_a, _stack *stack_a, _stack *stack_b)
{
	int	median_b;
	int	i_b;
	int	median_a;
	int	i_a;

	i_b = stack_b->size - index_b;
	i_a = stack_a->size - index_a;
	median_b = stack_b->size / 2;
	median_a = stack_a->size / 2;
	if (index_b > median_b && index_a > median_a)
	{
		while (i_b > 0 && i_a > 0)
		{
			rrr(stack_a, stack_b);
			i_b--;
			i_a--;
		}
		while (i_b > 0)
		{
			rev_rotate(stack_b, 'b');
			i_b--;
		}
		while (i_a > 0)
		{
			rev_rotate(stack_a, 'a');
			i_a--;
		}
	}
	else if (index_b <= median_b && index_a <= median_a)
	{
		while (index_b > 0 && index_a > 0)
		{
			rr(stack_a, stack_b);
			index_b--;
			index_a--;
		}
		while (index_b > 0)
		{
			rotate(stack_b, 'b');
			index_b--;
		}
		while (index_a > 0)
		{
			rotate(stack_a, 'a');
			index_a--;
		}
	}
	else
		push_to_target_b_separ(index_b, index_a, stack_a, stack_b);
	push_b(stack_a, stack_b);
}
/* int set_cost(int index_b, _stack *stack_b, int index_a, _stack *stack_a)
{
	int median_a;
	int median_b;
	int total_cost;

	median_a = stack_a->size / 2;
	median_b = stack_b->size / 2;
	total_cost = 0;

	if (index_b <= median_b)
		total_cost += index_b;
	if (index_b > median_b)
		total_cost += stack_b->size - index_b;
	if (index_a <= median_a)
		total_cost += index_a;
	if (index_a > median_a)
		total_cost += stack_a->size - index_a;
	return (total_cost);
} */
int	set_cost(int index_b, _stack *stack_b, int index_a, _stack *stack_a)
{
	int	median_a;
	int	median_b;
	int	total_cost;
	int	min_index;
	int	i_b;
	int	i_a;

	median_a = stack_a->size / 2;
	median_b = stack_b->size / 2;
	i_b = stack_b->size - index_b;
	i_a = stack_a->size - index_a;
	total_cost = 0;

	if (index_b <= median_b && index_a <= median_a)
	{
		// Shared rotations (rr)
		min_index = index_b;
		if (index_a < index_b)
			min_index = index_a;

		total_cost += min_index;

		if (index_b > index_a)
			total_cost += (index_b - index_a);
		else
			total_cost += (index_a - index_b);
	}
	else if (index_b > median_b && index_a > median_a)
	{
		// Shared reverse rotations (rrr)
		min_index = i_b;
		if (i_a < i_b)
			min_index = i_a;

		total_cost += min_index;

		if (i_b > i_a)
			total_cost += (i_b - i_a);
		else
			total_cost += (i_a - i_b);
	}
	else
	{
		// Separate rotations
		if (index_b <= median_b)
			total_cost += index_b;
		else
			total_cost += stack_b->size - index_b;

		if (index_a <= median_a)
			total_cost += index_a;
		else
			total_cost += stack_a->size - index_a;
	}

	return (total_cost);
}

void	sort_big(_stack *stack_a, _stack *stack_b)
{
	int index_b;
	int index_a;

	while (stack_a->size > 3)
	{
		index_b = 0;
		index_a = 0;
		stack_a->cheapest = INT_MAX;
		while (index_a < stack_a->size)
		{
			if (stack_b->size <= 1)
			{
				push_b(stack_a, stack_b);
				break ;
			}
			else
			{
				index_b = check_target(stack_a->arr[index_a], stack_b);
				stack_a->push_cost = set_cost(index_b, stack_b, index_a, stack_a);
				if (stack_a->push_cost < stack_a->cheapest)
				{
					stack_a->cheapest = stack_a->push_cost;
					stack_a->cheapest_index = index_a;
					stack_a->target_index = index_b;
				}
			}
			index_a++;
		}
		if (stack_a->size > 3)
			push_to_target_b(stack_a->target_index, stack_a->cheapest_index, stack_a, stack_b);
	}
}


int	find_smallest(_stack *stack_a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = stack_a->arr[0];
	min_index = 0;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < min)
		{
			min = stack_a->arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int find_target_in_a(_stack *stack_a, int num_in_stack_b)
{
	int	i;
	int	closest_bigger;
	int	target_index;

	i = 0;
	closest_bigger = INT_MAX;
	target_index = -1;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > num_in_stack_b && stack_a->arr[i] <= closest_bigger)
		{
			closest_bigger = stack_a->arr[i];
			target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = find_smallest(stack_a);
	return (target_index);
}
//TODO : create a set median function to set both medians and save them as a stack info
void	push_to_a(int index_a, _stack *stack_a,int index_b, _stack *stack_b)
{
	int i_a;
	int i_b;
	int median_a;
	int median_b;

	median_a = stack_a->size / 2;
	median_b = stack_b->size / 2;
	i_a = stack_a->size - index_a;
	i_b = stack_b->size - index_b;
	if (index_a > median_a)
	{
		while (i_a--)
			rev_rotate(stack_a, 'a');
	}
	if (index_a <= median_a)
	{
		while (index_a--)
			rotate (stack_a, 'a');
	}
	if (index_b > median_b)
	{
		while(i_b--)
			rev_rotate(stack_b, 'b');
	}
	if (index_b <= median_b)
	{
		while (index_b--)
			rotate(stack_b, 'b');
	}
	push_a(stack_a, stack_b);
}

void push_back_to_a(_stack *stack_a, _stack *stack_b)
{
	int index_a;
	int index_b;

	index_a = 0;
	index_b = 0;
	stack_b->cheapest = INT_MAX;
	while (index_b < stack_b->size)
	{
		index_a = find_target_in_a(stack_a, stack_b->arr[index_b]);
		stack_b->push_cost = set_cost(index_b, stack_b, index_a, stack_a);
		if (stack_b->push_cost < stack_b->cheapest)
		{
			stack_b->cheapest = stack_b->push_cost;
			stack_b->cheapest_index = index_b;
			stack_b->target_index = index_a;
		}
		index_b++;
	}
	push_to_a(stack_b->target_index, stack_a, stack_b->cheapest_index, stack_b);
}
void final_sort_a(_stack *stack_a)
{
	int min_index;
	int median;
	int rev_rotate_step;

	min_index = find_smallest(stack_a);
	median = stack_a->size / 2;
	if (min_index <= median)
	{
		while (min_index--)
			rotate(stack_a, 'a');
	}
	else if (min_index > median)
	{
		rev_rotate_step = stack_a->size - min_index;
		while (rev_rotate_step--)
			rev_rotate(stack_a, 'a');
	}
}
void sort_stack(_stack *stack_a, _stack *stack_b)
{
	while (stack_a->size > 3)
	{
		sort_big(stack_a, stack_b);
	}
	if (stack_a->size <= 3)
	{
		min_sort(stack_a);
	}
	while (stack_b->size)
		push_back_to_a(stack_a, stack_b);
	if (is_sorted (stack_a) == -1)
		final_sort_a(stack_a);
}
