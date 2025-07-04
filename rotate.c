/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:48:53 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 19:15:35 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, bool check)
{
	int	i;
	int	temp;

	if (stack->size_a < 2)
		return ;
	i = stack->size_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = temp;
	if (check)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, bool check)
{
	int	i;
	int	temp;

	if (stack->size_a < 2)
		return ;
	i = stack->size_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = temp;
	if (check)
		ft_printf("rrb\n");
}

void	ra(t_stack *stack, bool check)
{
	int	i;
	int	temp;

	i = 0;
	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	while (i < stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = temp;
	if (check)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, bool check)
{
	int	i;
	int	temp;

	i = 0;
	if (stack->size_a < 2)
		return ;
	temp = stack->stack_b[0];
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = temp;
	if (check)
		ft_printf("rb\n");
}
