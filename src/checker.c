/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:28:54 by binam             #+#    #+#             */
/*   Updated: 2022/03/17 13:03:04 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_and_reply(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;

	j = -1;
	i = 1;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (-1);
		i++;
	}
	i = -1;
	argc--;
	while (argc > 0)
	{
		k = 0;
		while (++k < argc)
			if (ft_atoi(argv[argc - 1]) == ft_atoi(argv[k - 1]))
				return (-1);
		argc--;
	}
	return (1);
}

int	check_lineup(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argc > 2)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			i++;
		else
			return (1);//sıralı degilse 1 sıralıysa -1 don
		argc--;
	}
	return (-1);
}
