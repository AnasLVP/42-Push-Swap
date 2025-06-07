/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 15:42:40 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min(t_list **firsta, int min)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *firsta;
	while (temp)
	{
		if (((t_elem *)temp->content)->rank == min)
			break ;
		i++;
		temp = temp->next;
	}
	if (i <= ft_lstsize(*firsta) / 2)
	{
		while (((t_elem *)(*firsta)->content)->rank != min)
			ft_ra(firsta);
	}
	else
	{
		while (((t_elem *)(*firsta)->content)->rank != min)
			ft_rra(firsta);
	}
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
