/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:06:56 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/04 19:45:15 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft.h"
# include <limits.h>
# include <stdbool.h>

# define ERROR_MESSAGE "Error\n"

typedef struct s_stack
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}		t_stack;

// sorting
void	sort_three(t_stack *stack);
void	sort_4_5(t_stack *stack);
void	radix(t_stack *stack);
void	push_swap(t_stack *stack);
// algorithm utils
int		find_biggest(int *stack, int size);
int		find_smallest(int *stack, int size);
int		find_position(int *stack, int size, int min);
bool	issorted(t_stack *stack);
// parsing
char	**get_args(int size, char **input_arr);
bool	is_valid(char **arr);
bool	no_duplicates(char **str);
bool	is_only_ints(char *str);
// push
void	pb(t_stack *stack);
void	pa(t_stack *stack);
// rotate
void	ra(t_stack *stack, bool check);
void	rb(t_stack *stack, bool check);
void	rra(t_stack *stack, bool check);
void	rra(t_stack *stack, bool check);
void	rrb(t_stack *stack, bool check);
void	rr(t_stack *stack, bool check);
void	rrr(t_stack *stack, bool check);
// swap
void	sa(t_stack *stack, bool check);
void	sb(t_stack *stack, bool check);
void	ss(t_stack *stack, bool check);
// utils
char	**get_args(int size, char **arr);
int		get_stack_size(char **arr);
int		*fill_stack(char **arr, int size);
char	**parse_arr(int argc, char **argv);
int		p_error(void);
bool	less_than_two_signs(char *arr);
// printf
int		ft_put_hexa_lower(unsigned long num);
int		ft_put_hexa_upper(unsigned long num);
int		ft_put_ptr(void *ptr);
int		switch_function(char *c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_putchar_printf(char c);
int		ft_pustr_printf(char *str);
int		ft_putnbr_printf(int n);
int		ft_put_un_nbr_printf(unsigned int n);
#endif