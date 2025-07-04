/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:17:43 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 18:59:40 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	biggest;

	if (stack->size_a == 1)
		return ;
	biggest = find_biggest(stack->stack_a, stack->size_a);
	if (biggest == stack->stack_a[0] && stack->size_a == 3)
		ra(stack, true);
	else if (biggest == stack->stack_a[1] && stack->size_a == 3)
		rra(stack, true);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack, true);
}

void	sort_4_5(t_stack *stack)
{
	int	min;
	int	i;
	int	size;

	size = stack->size_a;
	i = 0;
	while (i++ < size - 3)
	{
		min = find_smallest(stack->stack_a, stack->size_a);
		while (stack->stack_a[0] != min)
		{
			if (find_position(stack->stack_a,
					stack->size_a, min) <= stack->size_a / 2)
				ra(stack, true);
			else
				rra(stack, true);
		}
		pb(stack);
	}
	sort_three(stack);
	while (stack->size_b > 0)
		pa(stack);
}

void	radix(t_stack *stack)
{
	int	i;
	int	j;
	int	max_num;
	int	max_bits;
	int	size;

	max_num = stack->size_a - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = stack->size_a;
		while (++j < size)
		{
			if (((stack->stack_a[0] >> i) & 1) == 1)
				ra(stack, true);
			else
				pb(stack);
		}
		while (stack->size_b > 0)
			pa(stack);
	}
}

void	push_swap(t_stack *stack)
{
	stack->stack_b = malloc(sizeof(int) * stack->size_a);
	stack->size_b = 0;
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		return ;
	}
	if (stack->size_a == 4 || stack->size_a == 5)
		sort_4_5(stack);
	else
		radix(stack);
	free(stack->stack_b);
}
