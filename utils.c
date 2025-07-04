/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:22:41 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 19:55:07 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*fill_stack(char **arr, int size)
{
	int		i;
	long	num;
	int		*filled_stack;

	filled_stack = malloc(sizeof(int) * size);
	if (!filled_stack)
		return (NULL);
	i = 0;
	while (arr[i] && i < size)
	{
		if (!less_than_two_signs(arr[i]))
			return (free(filled_stack), NULL);
		num = ft_atoi(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(filled_stack);
			return (NULL);
		}
		filled_stack[i] = (int)num;
		i++;
	}
	return (filled_stack);
}

char	**parse_arr(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = get_args(argc, argv);
	return (argv);
}

bool	less_than_two_signs(char *arr)
{
	int	i;
	int	flaga;

	i = 0;
	flaga = 0;
	if (!arr)
		return (false);
	while (arr[i])
	{
		if (arr[i] == '-' || arr[i] == '+')
			flaga++;
		if (flaga >= 2)
			return (false);
		i++;
	}
	if (i == 1 && flaga == 1)
		return (false);
	return (true);
}
