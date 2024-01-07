/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:32:00 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 17:48:42 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	int	i;
	int	*new;

	i = 0;
	new = ft_calloc(stacks->size_a + 1, sizeof(int *));
	new[0] = stacks->stack_a[stacks->size_a - 1];
	while (stacks->stack_a[i + 1])
	{
		new[i + 1] = stacks->stack_a[i];
		i++;
	}
	free(stacks->stack_a);
	stacks->stack_a = new;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	int	i;
	int	*new;

	i = 0;
	new = ft_calloc(stacks->size_b + 1, sizeof(int *));
	new[0] = stacks->stack_b[stacks->size_b - 1];
	while (stacks->stack_b[i + 1])
	{
		new[i + 1] = stacks->stack_b[i];
		i++;
	}
	free(stacks->stack_b);
	stacks->stack_b = new;
	ft_printf("rrb\n");
}

void	ra(t_stacks *stacks)
{
	int	i;
	int	*new;

	new = ft_calloc(stacks->size_a, sizeof(int *));
	new[stacks->size_a - 1] = stacks->stack_a[0];
	i = 0;
	while (stacks->stack_a[i + 1])
	{
		new[i] = stacks->stack_a[i + 1];
		i++;
	}
	free(stacks->stack_a);
	stacks->stack_a = new;
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	int	i;
	int	*new;

	new = ft_calloc(stacks->size_b, sizeof(int *));
	new[stacks->size_b - 1] = stacks->stack_b[0];
	i = 0;
	while (stacks->stack_b[i + 1])
	{
		new[i] = stacks->stack_b[i + 1];
		i++;
	}
	new[i] = stacks->stack_b[0];
	free(stacks->stack_b);
	stacks->stack_b = new;
	ft_printf("rb\n");
}
