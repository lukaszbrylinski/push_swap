/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:44:53 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 19:34:41 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_error(void)
{
	ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit (1);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->stack_a)
		free(stack->stack_a);
	free(stack);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_and_close(t_stack *stack, char **arr)
{
	free_stack(stack);
	free_arr(arr);
	p_error();
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (1);
	stack->stack_a = NULL;
	if (argc == 1 || !argv[1])
		return (p_error());
	arr = parse_arr(argc, argv);
	if (!arr || !is_valid(arr))
		free_and_close(stack, arr);
	stack->size_a = get_stack_size(arr);
	stack->stack_a = fill_stack(arr, stack->size_a);
	free_arr(arr);
	if (!stack->stack_a)
		free_and_close(stack, NULL);
	if (!issorted(stack))
	{
		if (stack->size_a <= 3)
			sort_three(stack);
		else
			push_swap(stack);
	}
	return (free_stack(stack), 0);
}
