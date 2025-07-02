/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:56 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/02 15:17:07 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "./libft.h"

# define ERROR_MESSAGE \
	"Error\n"

typedef struct s_stack
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}		t_stack;

void	sort_three(t_stack *stack);
void	sort_4_5(t_stack *stack);
void	radix(t_stack *stack);
void	push_swap(t_stack *stack);
////////////////////////////////////
int		strlen_ft(const char *str, char seperator, int start);
int		count_words(const char *str, char seperator);
char	**cleanup(char **str_arr, int word_num);
char	**ft_split(char const *s, char c);

//push
void	pb(t_stack *stack);
void	pa(t_stack *stack);
//rotate
void	ra(t_stack *stack, bool check);
void	rra(t_stack *stack, bool check);

#endif