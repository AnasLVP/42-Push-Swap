/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 13:59:32 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_astack(char **args, int size)
{
	int	i;
	int	*res;

	i = 1;
	res = malloc(sizeof(int) * (size - 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i - 1] = (int)ft_atoi(args[i]);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	*stacka;

	if (ac == 1)
		return (0);
	if (!parse_args(av) || !only_uniques(av, ac - 1))
		return (write(2, "Error\n", 6));
	stacka = make_astack(av, ac);
	free(stacka);
	return (0);
}
