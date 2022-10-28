/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:26:14 by binam             #+#    #+#             */
/*   Updated: 2022/10/24 19:26:16 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort(int *sort, t_data *a)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		sort[i] = a->array[i];
		i++;
	}	
	i = -1;
	while (++i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (sort[i] > sort[j])
			{
				tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = tmp;
			}
			j++;
		}
	}
}

void	indexing(t_data *a)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * a->size);
	ft_sort(tmp, a);
	i = 0;
	while (i < a->size)
	{
		j = -1;
		while (++j < a->size)
		{
			if (a->array[i] == tmp[j])
			{
				a->array[i] = j;
				break ;
			}	
		}
		i++;
	}
	free(tmp);
}
