#include "push_swap.h"

int	get_min_ind(t_stack *stack_a)
{
	int	j;
	int	i;
	int	min;

	if (!stack_a->size)
		return (0);
	min = INT_MAX;
	i = -1;
	j = 0;
	while (++i < stack_a->size)
	{
		if (stack_a->arr[i] < min)
		{
			min = stack_a->arr[i];
			j = i;
		}
	}
	return (j);
}

int	get_pos(t_stack *stack_a, int num)
{
	int	j;
	int	i;
	int	max;
	int	tmp;

	if (!stack_a->size)
		return (1);
	max = INT_MIN;
	j = -1;
	i = -1;
	while (++i < stack_a->size)
	{
		tmp = num - stack_a->arr[i];
		if (tmp < 0 && tmp > max)
		{
			j = i;
			max = tmp;
		}
	}
	if (j == -1)
		j = get_min_ind(stack_a);
	return (j);
}

void	find_least_process(t_stack *stack_a, t_stack *stack_b, int *i, int *j)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = INT_MAX;
	m = stack_b->size;
	while (--m >= 0)
	{
		n = get_pos(stack_a, stack_b->arr[m]);
		if (m + 1 > stack_b->size - m - 1)
			tmp[0] = stack_b->size - m - 1;
		else
			tmp[0] = m + 1;
		if (n > stack_a->size - n)
			tmp[1] = stack_a->size - n;
		else
			tmp[1] = n;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i = m;
			*j = n;
		}
	}
}

void	get_to_top(t_stack *s, int i)
{
	int	counter;

	if (i + 1 > s->size - i - 1)
	{
		counter = s->size - i - 1;
		while (counter-- > 0)
			rotate(s);
	}
	else
	{
		counter = i + 1;
		while (counter-- > 0)
			rev_rotate(s);
	}
}

void	ft_rec(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	while (stack_b->size > 0)
	{
		find_least_process(stack_a, stack_b, &i, &j);
		get_to_top(stack_b, i);
		get_to_top(stack_a, j);
		push(stack_b, stack_a, 'a');
	}
	get_to_top(stack_a, get_min_ind(stack_a));
}
