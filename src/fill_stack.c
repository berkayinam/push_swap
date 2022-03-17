/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:28:22 by binam             #+#    #+#             */
/*   Updated: 2022/03/16 17:28:41 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, char type, char **argv, int argc)
{
	if (type == 'a')
	{
		stack->type = 'a';
		stack->size = argc - 1;
		stack->maxsize = argc - 1;
		stack->arr = malloc(sizeof(int) * (argc - 1));
		argc--;
		while (argc >= 1)
		{
			stack->arr[argc - 1] = ft_atoi(argv[argc]);
			argc--;
		}
	}
	else
	{
		stack->size = 0;
		stack->type = 'b';
		stack->arr = malloc(sizeof(int) * (argc - 1));
		stack->maxsize = argc - 1;
	}
}
