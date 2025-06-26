/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:04:32 by lbrylins          #+#    #+#             */
/*   Updated: 2024/12/17 17:09:23 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	strlen_ft(const char *str, char seperator, int start)
{
	int	i;
	int	len;

	i = start;
	len = 0;
	while (str[i] && str[i] != seperator)
	{
		i++;
		len++;
	}
	return (len);
}

int	count_words(const char *str, char seperator)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == seperator)
			str++;
		if (*str)
		{
			count++;
			while (*str != seperator && *str)
				str++;
		}
	}
	return (count);
}

char	**cleanup(char **str_arr, int word_num)
{
	while (word_num > 0)
		free(str_arr[word_num--]);
	free(str_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		word_num;
	int		i;

	if (!s)
		return (NULL);
	str_arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	word_num = 0;
	i = 0;
	while (word_num < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		str_arr[word_num] = ft_substr(s, i, strlen_ft(s, c, i));
		if (str_arr[word_num] == NULL)
			return (cleanup(str_arr, word_num));
		i += strlen_ft(s, c, i);
		word_num++;
	}
	str_arr[word_num] = NULL;
	return (str_arr);
}
