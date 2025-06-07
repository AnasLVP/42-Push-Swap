/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 16:59:14 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back(t_list **firsta, t_list **firstb)
{
	int	i;
	int	size;

	size = ft_lstsize(*firsta);
	i = 0;
	if (size == 3)
		sort_three(firsta);
	else
		rotate_to_min(firsta, lst_min(*firsta));
	rotate_to_max(firstb, lst_max(*firstb));
	while (*firstb && i < size)
	{
		if (((t_elem *)(*firstb)->content)->rank <
			((t_elem *)(ft_lstlast(*firsta))->content)->rank)
		{
			ft_rra(firsta);
			i++;
		}
		else
			ft_pa(firsta, firstb);
	}
	while (*firstb)
		ft_pa(firsta, firstb);
	rotate_to_min(firsta, lst_min(*firsta));
}

void	push_swap(t_list **firsta, t_list **firstb)
{
	ft_pb(firsta, firstb);
	ft_pb(firsta, firstb);
	while (ft_lstsize(*firsta) > 3 || !ft_lstsorted(*firsta, 1))
		rotatelists(firsta, firstb, (min_operations(*firsta, *firstb)));
	push_back(firsta, firstb);
}

static int	check_args(int ac, char ***av)
{
	int		i;
	char	**split;
	char	*args;

	i = 0;
	if (ac == 2)
	{
		args = ft_strjoin("push_swap ", (*av)[1]);
		split = ft_split(args, ' ');
		*av = split;
		while (split[i])
			i++;
		free(args);
		return (i);
	}
	return (ac);
}

static int	pars_args(int ac, char **av, int count)
{
	if (!parse_args(av) || !only_uniques(av, count - 1))
	{
		if (ac == 2)
			ft_freeall(av);
		return (write(2, "Error\n", 6));
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*firsta;
	t_list	*firstb;
	int		count;

	firsta = NULL;
	firstb = NULL;
	if (ac == 1)
		return (0);
	count = check_args(ac, &av);
	if (pars_args(ac, av, count))
		return (0);
	create_list(&firsta, av, count);
	ft_lstnormalize(&firsta);
	if (ft_lstsorted(firsta, 1))
		rotate_to_min(&firsta, lst_min(firsta));
	else if (ft_lstsize(firsta) > 3)
		push_swap(&firsta, &firstb);
	else
		sort_three(&firsta);
	if (ac == 2)
		ft_freeall(av);
	ft_lstclear(&firsta, &free);
	return (0);
}
