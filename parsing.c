/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:17:52 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 19:55:00 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int argc, char **arr)
{
	char	**out_arr;
	int		i;

	out_arr = malloc(sizeof(char *) * argc);
	if (!out_arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		out_arr[i - 1] = ft_strdup(arr[i]);
		if (!out_arr[i - 1])
			return (NULL);
		i++;
	}
	out_arr[i - 1] = NULL;
	return (out_arr);
}

bool	is_valid(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (false);
	if (!no_duplicates(arr))
	{
		return (false);
	}
	while (arr[i])
	{
		if (!is_only_ints(arr[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	no_duplicates(char **str)
{
	int	i;
	int	j;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strlen(str[i]) == ft_strlen(str[j]) && ft_strncmp(str[i],
					str[j], ft_strlen(str[i])) == 0)
				return (false);
			j++;
		}
		i++;
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
