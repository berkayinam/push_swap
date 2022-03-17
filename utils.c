/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:16:43 by binam             #+#    #+#             */
/*   Updated: 2022/03/17 12:25:50 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to, char type)
{
	from->size--;
	to->arr[to->size] = from->arr[from->size];
	to->size++;
	if (type == 'a')
		ft_putstr("pa\n");
	else
		ft_putstr("pb\n");
}

void	rotate(t_stack *stack)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * stack->maxsize);
	i = -1;
	while (++i < stack->size)
		new_arr[(i + 1) % stack->size] = stack->arr[i];
	if (stack->type == 'a')
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
	free(stack->arr);
	stack->arr = new_arr;
}

void	rev_rotate(t_stack *stack)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * stack->maxsize);
	i = -1;
	while (++i < stack->size)
		new_arr[i] = stack->arr[(i + 1) % stack->size];
	if (stack->type == 'a')
		ft_putstr("rra\n");
	else
		ft_putstr("rrb\n");
	free(stack->arr);
	stack->arr = new_arr;
}

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->arr[stack->size - 2];
	stack->arr[stack->size - 2] = stack->arr[stack->size - 1];
	stack->arr[stack->size - 1] = tmp;
	if (stack->type == 'a')
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

int	get_average(t_stack *stack, int size)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	min = INT_MAX;
	max = INT_MIN;
	while (++i < size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		if (stack->arr[i] < min)
			min = stack->arr[i];
	}
	return ((max + min) / 2);
}
