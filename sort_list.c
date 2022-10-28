/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:59 by binam             #+#    #+#             */
/*   Updated: 2022/10/24 19:26:01 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	bit_count(t_data *a_stack)
{
	int	bit_size;
	int	size;

	bit_size = 0;
	size = a_stack->size;
	while (size > 1)
	{
		bit_size++;
		size /= 2;
	}
	return (bit_size);
}

void	sort_list_b(t_data *a, t_data *b, int bit, int bit_size)
{
	int	i;
	int	size;

	i = -1;
	size = b->size;
	if (bit <= bit_size)
	{
		while (++i < size)
		{
			if (((b->array[b->size - 1] >> bit) & 1) == 0)
				rotate(b);
			else
				push(b, a);
		}
	}
}

void	bitwise_a(t_data *a, t_data *b, int bit)
{
	if (((a->array[a->size - 1] >> bit) & 1) == 0)
		push(a, b);
	else
		rotate(a);
}

void	sort_list(t_data *a, t_data *b)
{
	int	bit;
	int	i;
	int	size;
	int	bit_size;

	bit = -1;
	bit_size = bit_count(a);
	while (++bit <= bit_size)
	{
		i = -1;
		size = a->size;
		if (bit <= bit_size)
		{
			while (++i < size)
				if (check_in_line2(a))
					bitwise_a(a, b, bit);
			sort_list_b(a, b, bit + 1, bit_size);
		}
	}
	while (b->size)
		push(b, a);
}
