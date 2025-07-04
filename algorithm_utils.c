/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:01:14 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 17:55:20 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (i < size)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

int	find_smallest(int *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack[0];
	while (i < size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}

int	find_position(int *stack, int size, int min)
{
	int	i;

	i = 0;
	while (i < size && stack[i] != min)
		i++;
	return (i);
}

bool	issorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}
