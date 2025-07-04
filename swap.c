/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:50:05 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 17:11:51 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, bool check)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	if (check)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, bool check)
{
	int	temp;

	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
	if (check)
		ft_printf("sb\n");
}

void	ss(t_stack *stack, bool check)
{
	sa(stack, check);
	sb(stack, check);
}
