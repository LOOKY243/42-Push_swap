/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:44:38 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 14:58:20 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		find_best_push_to_b(stacks);
		push_top_a(stacks);
		push_top_b(stacks);
		pb(stacks);
		ft_printf("pb\n");
	}
}

int	find_max(int *stack, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		if (stack[i] > stack[n])
			n = i;
		i++;
	}
	return (n);
}

int	find_target_node_b(t_stacks *stacks, int a_pos)
{
	int	i;
	int	res;
	int	num;

	i = 0;
	res = INT_MIN;
	num = -1;
	while (i < stacks->size_b)
	{
		if (stacks->stack_b[i] > res
			&& stacks->stack_a[a_pos] > stacks->stack_b[i])
		{
			res = stacks->stack_b[i];
			num = i;
		}
		i++;
	}
	if (num == -1)
		return (find_max(stacks->stack_b, stacks->size_b));
	return (num);
}

int	count_swaps(t_stacks *stacks, int b_pos, int a_pos)
{
	int	count;

	if (a_pos > stacks->size_a / 2)
		count = stacks->size_a - a_pos;
	else
		count = a_pos;
	if (b_pos > stacks->size_b / 2)
		count += stacks->size_b - b_pos;
	else
		count += b_pos;
	return (count);
}

void	find_best_push_to_b(t_stacks *stacks)
{
	int	i;
	int	best;

	best = count_swaps(stacks, find_target_node_b(stacks, 0), 0);
	stacks->a_pos = 0;
	stacks->b_pos = find_target_node_b(stacks, 0);
	if (best == 0)
		return ;
	i = 1;
	while (stacks->stack_a[i])
	{
		if (count_swaps(stacks, find_target_node_b(stacks, i), i) < best)
		{
			best = count_swaps(stacks, find_target_node_b(stacks, i), i);
			stacks->a_pos = i;
			stacks->b_pos = find_target_node_b(stacks, i);
			if (best == 0)
				return ;
		}
		i++;
	}
}
