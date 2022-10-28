/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:26:36 by binam             #+#    #+#             */
/*   Updated: 2022/10/24 19:26:39 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	triple_list(t_data *a)
{
	if (!(a->array[0] > a->array[1] && a->array[0] > a->array[2]))
	{
		if (a->array[1] > a->array[2])
			rev_rotate(a);
		else if (a->array[2] > a->array[1])
			rotate(a);
	}
	if (a->array[2] > a->array[1])
		swap(a);
}

void	quartet_list(t_data *a, t_data *b)
{
	if (a->array[3] != 0)
	{
		if (a->array[2] == 0)
			rotate(a);
		else if (a->array[1] == 0)
		{
			rev_rotate(a);
			rev_rotate(a);
		}
		else if (a->array[0] == 0)
			rev_rotate(a);
	}
	push(a, b);
	triple_list(a);
	push(b, a);
}

void	quintuple_list(t_data *a, t_data *b)
{
	int	i;

	i = 4;
	while (i > 2)
	{
		if (a->array[i] == 0 || a->array[i] == 1)
		{
			push(a, b);
			i--;
		}
		else
			rotate(a);
	}
	if (b->array[0] > b->array[1])
		swap(b);
	triple_list(a);
	push(b, a);
	push(b, a);
}

void	sort_smaller_list(t_data *a, t_data *b)
{
	if (a->size == 2)
		swap(a);
	else if (a->size == 3)
		triple_list(a);
	else if (a->size == 4)
		quartet_list(a, b);
	else if (a->size == 5)
		quintuple_list(a, b);
}
