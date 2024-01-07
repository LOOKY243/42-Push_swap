/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:42:08 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 17:56:58 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_top_a(t_stacks *stacks)
{
	if (stacks->a_pos > stacks->size_a / 2 && stacks->a_pos != 0)
	{
		while (stacks->a_pos != stacks->size_a && stacks->a_pos != 0)
		{
			rra(stacks);
			stacks->a_pos++;
		}
	}
	else
	{
		while (stacks->a_pos > 0)
		{
			ra(stacks);
			stacks->a_pos--;
		}
	}
}

void	push_top_b(t_stacks *stacks)
{
	if (stacks->b_pos > stacks->size_b / 2 && stacks->b_pos != 0)
	{
		while (stacks->b_pos != stacks->size_b && stacks->b_pos != 0)
		{
			rrb(stacks);
			stacks->b_pos++;
		}
	}
	else
	{
		while (stacks->b_pos > 0)
		{
			rb(stacks);
			stacks->b_pos--;
		}
	}
}

void	sorting(t_stacks *stacks)
{
	if (stacks->size_a >= 4)
	{
		pb(stacks);
		pb(stacks);
		ft_printf("pb\npb\n");
		a_to_b(stacks);
		sort_a(stacks);
		b_to_a(stacks);
		while (find_min(stacks) != 0)
		{
			if (find_min(stacks) > stacks->size_a / 2)
				rra(stacks);
			else
				ra(stacks);
		}
	}
	else
	{
		if (stacks->size_a == 3)
			sort_a(stacks);
		else if (find_min(stacks) != 0)
			sa(stacks);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac == 1)
		return (FALSE);
	stacks.stack_b = ft_calloc(1, sizeof(int *));
	stacks.size_a = 0;
	stacks.size_b = 0;
	if (!get_args(av, &stacks))
	{
		free(stacks.stack_a);
		free(stacks.stack_b);
		return (FALSE);
	}
	sorting(&stacks);
	free(stacks.stack_a);
	free(stacks.stack_b);
}
