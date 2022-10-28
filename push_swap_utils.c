/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:26:25 by binam             #+#    #+#             */
/*   Updated: 2022/10/24 19:26:27 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_data *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = stack->array[stack->size - 2];
	stack->array[stack->size - 2] = tmp;
	if (stack->type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push(t_data *from, t_data *to)
{
	if (from->size < 1)
		return ;
	to->array[to->size] = from->array[from->size - 1];
	to->size++;
	from->size--;
	if (from->type == 'a')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	rotate(t_data *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	i = -1;
	while (++i < stack->size -1)
		stack->array[stack->size - i - 1] = stack->array[stack->size - i - 2];
	stack->array[0] = tmp;
	if (stack->type == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rev_rotate(t_data *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	i = -1;
	while (++i < stack->size - 1)
		stack->array[i] = stack->array[i + 1];
	stack->array[stack->size - 1] = tmp;
	if (stack->type == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
