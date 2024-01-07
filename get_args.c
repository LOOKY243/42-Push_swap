/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:47:06 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/07 16:20:15 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
			return (FALSE);
		if ((str[i] == '-' || str[i] == '+') && i != 0 && str[i - 1] >= '0'
			&& str[i + 1] <= '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	find_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (TRUE);
		i++;
	}
	return (return_errors());
}

int	put_in_board(char **nums, t_stacks *stacks)
{
	int	j;
	int	trigger;

	j = 0;
	trigger = 0;
	while (j < count_splits(nums))
	{
		if (ft_atoi(nums[j]) == 0 && nums[j][0] != '0')
			trigger = 1;
		if (!ft_isdigit(nums[j]) || trigger == 1)
		{
			j--;
			while (nums[++j])
				if (nums[j])
					free(nums[j]);
			return (return_errors());
		}
		stacks->stack_a[j] = ft_atoi(nums[j]);
		stacks->size_a++;
		free(nums[j]);
		j++;
	}
	return (TRUE);
}

int	check_repeat(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 1;
	while (i < stacks->size_a)
	{
		j = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j] && i != j)
				return (return_errors());
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	get_args(char **av, t_stacks *stacks)
{
	int		i;
	char	*tmp;
	char	*num;
	char	**nums;

	i = 0;
	num = NULL;
	while (av[++i])
	{
		if (!find_digit(av[i]))
			return (FALSE);
		tmp = ft_strjoin(num, av[i]);
		free(num);
		num = tmp;
	}
	nums = ft_split(num, ' ');
	stacks->stack_a = ft_calloc(count_splits(nums), sizeof(int *));
	free(num);
	if (!put_in_board(nums, stacks) || !check_repeat(stacks))
	{
		free(nums);
		return (FALSE);
	}
	free(nums);
	return (TRUE);
}
