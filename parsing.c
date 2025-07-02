/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:17:52 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/02 16:40:33 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int size, char **input_arr)
{
	char	**out_arr;
	int		i;

	i = 1;
	out_arr = malloc(sizeof(char *) * (size -1));
	if (!out_arr)
		return (NULL);
	while (input_arr[i] && i < size)
	{
		out_arr[i-1] = ft_strdup(input_arr[i]);
		i++;
	}
	return (out_arr);
}

bool	is_valid(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		if (!is_only_ints(arr[i]))
			return (false);
		if (!no_duplicates(arr, i))
			return (false);
	}
	return (true);
}

bool	no_duplicates(char **str, int i)
{
	int	j;

	j = i + 1;
	while (str[i] && str[j])
	{
		if (!ft_strncmp(str[i], str[j], ft_strlen(str[i])));
			return (false);
		j++;
	}
	return (true);
}

bool	is_only_ints(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
