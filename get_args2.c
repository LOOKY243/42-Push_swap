/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:39:23 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/07 16:19:55 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	return_errors(void)
{
	write(2, "Error\n", 6);
	return (FALSE);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			counter;
	long int	res;

	res = 0;
	counter = 1;
	i = 0;
	while (str[i] >= 9 && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			counter = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (res * counter > INT_MAX || res * counter < INT_MIN)
		return (0);
	return (res * counter);
}

int	count_splits(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
