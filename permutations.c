/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:01:17 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 17:48:59 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	ft_printf("sb\n");
}

void	pa(t_stacks *stacks)
{
	int	i;
	int	*a;
	int	*b;

	if (!stacks->stack_b && !stacks->stack_a[1])
		return ;
	if (stacks->size_b - 1 != 0)
		b = ft_calloc(stacks->size_b, sizeof(int *));
	else
		b = ft_calloc(1, sizeof(int *));
	a = ft_calloc(stacks->size_a + 1, sizeof(int *));
	i = 0;
	while (++i < stacks->size_b)
		b[i - 1] = stacks->stack_b[i];
	i = stacks->size_a + 1;
	a[0] = stacks->stack_b[0];
	while (--i > 0)
		a[i] = stacks->stack_a[i - 1];
	free(stacks->stack_a);
	free(stacks->stack_b);
	stacks->stack_a = a;
	stacks->stack_b = b;
	stacks->size_a++;
	stacks->size_b--;
}

void	pb(t_stacks *stacks)
{
	int	i;
	int	*a;
	int	*b;

	if (!stacks->stack_a[0] && !stacks->stack_a[1])
		return ;
	if (stacks->size_a - 1 != 0)
		a = ft_calloc(stacks->size_a, sizeof(int *));
	else
		a = ft_calloc(1, sizeof(int *));
	b = ft_calloc(stacks->size_b + 1, sizeof(int *));
	i = 0;
	while (++i < stacks->size_a)
		a[i - 1] = stacks->stack_a[i];
	i = stacks->size_b + 1;
	b[0] = stacks->stack_a[0];
	while (--i > 0)
		b[i] = stacks->stack_b[i - 1];
	free(stacks->stack_a);
	free(stacks->stack_b);
	stacks->stack_a = a;
	stacks->stack_b = b;
	stacks->size_a--;
	stacks->size_b++;
}
