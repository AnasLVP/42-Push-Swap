/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:57:55 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 15:31:34 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	only_uniques(char **av, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size + 1)
	{
		j = 1;
		while (j < size + 1)
		{
			if (ft_strcmp(av[i], av[j]) == 0 && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_args(char **args)
{
	int		i;
	long	temp;

	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (0);
		if (!is_number(args[i]))
			return (0);
		temp = ft_atoi(args[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
