/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:44:53 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/02 17:11:04 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_error(void)
{
	ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit (1);
}

int	free_and_close(t_stack *stack, char	**arr)
{
	int	i;

	i = 0;
	if (stack)
		free(stack);
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	p_error();
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;

	stack = malloc(sizeof(*stack));
	if (argc == 1)
		return (p_error());
	else if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = get_args(argc, argv);
	if (!is_valid(arr))
		free_and_close(stack, arr);
	stack->size_a = get_stack_size(arr);
	stack->stack_a = fill_stack(arr, stack->size_a);
	free_arr(arr);
	if (!issorted(stack))
	{
		if (stack->size_a <= 3)
			sort_three(stack);
		else
			push_swap(stack);
	}
	free_stack(stack);
	return (0);
}
