/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:25:46 by binam             #+#    #+#             */
/*   Updated: 2022/10/24 19:25:48 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	int		*array;
	int		size;
	char	type;
}	t_data;

size_t	number_size(char const *av);
char	*substrr(char const *s, unsigned int start, size_t len);
int		atoii(const char *av, t_data *a_stack, t_data *b_stack);
size_t	splitt(char *av, t_data *a, t_data *b, size_t a_i);
size_t	ft_strlen(const char *s);
void	assign_to_stack(int ac, char **av, t_data *a_stack, t_data *b_stack);
void	check_repeat(t_data *a, t_data *b);
void	check_in_line(t_data *a, t_data *b);
int		check_in_line2(t_data *a);
void	ft_sort(int *sort, t_data *a);
void	indexing(t_data *a);
void	swap(t_data *stack);
void	push(t_data *from, t_data *to);
void	rotate(t_data *stack);
void	rev_rotate(t_data *stack);
void	triple_list(t_data *a);
void	quartet_list(t_data *a, t_data *b);
void	quintuple_list(t_data *a, t_data *b);
void	sort_smaller_list(t_data *a, t_data *b);
int		bit_count(t_data *a_stack);
void	sort_list_b(t_data *a, t_data *b, int bit, int bit_size);
void	bitwise_a(t_data *a, t_data *b, int bit);
void	sort_list(t_data *a, t_data *b);
void	error_mes(t_data *a, t_data *b);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif