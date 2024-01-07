/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:21:54 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 17:50:32 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	b_to_a(t_stacks *stacks)
{
	while (stacks->size_b != 0)
	{
		find_best_push_to_a(stacks);
		push_top_a(stacks);
		push_top_b(stacks);
		pa(stacks);
		ft_printf("pa\n");
	}
}

int	find_min(t_stacks *stacks)
{
	int	i;
	int	n;

	i = 0;
	n = i;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < stacks->stack_a[n])
			n = i;
		i++;
	}
	return (n);
}

void	sort_a(t_stacks *stacks)
{
	if (find_max(stacks->stack_a, stacks->size_a) != 2 && stacks->size_a == 3)
	{
		if (find_max(stacks->stack_a, stacks->size_a) == 1)
			rra(stacks);
		else
			ra(stacks);
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

int	find_target_node_a(t_stacks *stacks, int b_pos)
{
	int	i;
	int	res;
	int	num;

	i = 0;
	res = INT_MAX;
	num = -1;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] > stacks->stack_b[b_pos]
			&& stacks->stack_a[i] < res)
		{
			res = stacks->stack_a[i];
			num = i;
		}
		i++;
	}
	if (num == -1)
		return (find_min(stacks));
	return (num);
}

void	find_best_push_to_a(t_stacks *stacks)
{
	int	i;
	int	best;

	best = count_swaps(stacks, 0, find_target_node_a(stacks, 0));
	stacks->a_pos = find_target_node_a(stacks, 0);
	stacks->b_pos = 0;
	if (best == 0)
		return ;
	i = 1;
	while (stacks->stack_b[i])
	{
		if (count_swaps(stacks, find_target_node_a(stacks, i), i) < best)
		{
			best = count_swaps(stacks, i, find_target_node_a(stacks, i));
			stacks->a_pos = find_target_node_a(stacks, i);
			stacks->b_pos = i;
			if (best == 0)
				return ;
		}
		i++;
	}
}
