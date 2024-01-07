/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:49:48 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/28 14:57:56 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		str = malloc(sizeof(char) * ft_strlen(s2) + 2);
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = ' ';
	i++;
	str[i] = 0;
	return (str);
}
