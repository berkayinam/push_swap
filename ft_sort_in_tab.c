/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:27:24 by binam             #+#    #+#             */
/*   Updated: 2022/03/17 12:14:42 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_in_tab(t_stack stack_a)
{
	int		i;
	int		*temp;
	int		j;
	int		key;

	i = -1;
	temp = malloc(sizeof(int) * stack_a.size);
	while (++i < stack_a.size)
		temp[i] = stack_a.arr[i];
	i = 0;
	while (++i < stack_a.size)
	{
		j = i;
		key = temp[i];
		while (--j >= 0 && temp[j] > key)
			temp[j + 1] = temp[j];
		temp[j + 1] = key;
	}
	change_index(stack_a, temp);
}

void	change_index(t_stack stack_a, int *temp)
{
	int	key;
	int	i;
	int	j;

	i = -1;
	while (++i < stack_a.size)
	{
		j = 0;
		while (j < stack_a.size)
		{
			if (stack_a.arr[i] == temp[j])
				stack_a.arr[i] = j;
			j++;
		}
	}
	free(temp);
}
