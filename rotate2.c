/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:17:05 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 15:19:54 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack, bool check)
{
	ra(stack, check);
	rb(stack, check);
}

void	rrr(t_stack *stack, bool check)
{
	rra(stack, check);
	rrb(stack, check);
}
