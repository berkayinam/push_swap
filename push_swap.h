/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:19:47 by binam             #+#    #+#             */
/*   Updated: 2022/03/17 13:09:04 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		maxsize;
	char	type;
}			t_stack;

size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		ft_isdigit(char *str);
int		check_digit_and_reply(int argc, char **argv);
int		get_min_ind(t_stack *stack_a);
int		get_average(t_stack *stack, int size);
int		get_pos(t_stack *stack_a, int num);
void	fill_stack(t_stack *stack, char type, char **argv, int argc);
void	change_index(t_stack stack_a, int *temp);
void	ft_sort_in_tab(t_stack stack_a);
void	push(t_stack *from, t_stack *to, char type);
void	push_b(t_stack *stack_a, t_stack *stack_b, int size);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	ft_putstr(char *str);
void	find_least_process(t_stack *stack_a, t_stack *stack_b, int *i, int *j);
void	get_to_top(t_stack *s, int i);
void	ft_rec(t_stack *stack_a, t_stack *stack_b);
int		check_lineup(int argc, char **argv);

void	error(int i);

#endif
