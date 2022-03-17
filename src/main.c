/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:22:35 by binam             #+#    #+#             */
/*   Updated: 2022/03/17 13:08:34 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;
	int	average;
	int	j;

	i = -1;
	j = 0;
	if (size <= 2)
		return ;
	average = get_average(stack_a, size);
	while (++i < size)
	{
		if (stack_a->arr[stack_a->size - 1] <= average)
		{
			push(stack_a, stack_b, 'b');
			j++;
		}
		else
			rotate(stack_a);
	}
	push_b(stack_a, stack_b, size - j);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc >= 2)
	{
		if (check_digit_and_reply(argc, argv) && check_lineup(argc, &argv[1]))
			error(2);
		fill_stack(&stack_a, 'a', argv, argc);
		fill_stack(&stack_b, 'b', argv, argc);
		ft_sort_in_tab(stack_a);
		if (stack_a.size <= 5)
			;
		else
		{
			push_b(&stack_a, &stack_b, stack_a.size);
			ft_rec(&stack_a, &stack_b);
		}
	}
	else
		error(1);
}
