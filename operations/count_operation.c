/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:31:02 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/05 15:23:15 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	tab_zero(int *tab, int i, int x)
{
	tab[i] = 0;
	tab[x] = 0;
}

void	total_ops(int *tab)
{
	int	min;

	min = (ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]));
	if (min > ft_max(tab[0], tab[2]))
		min = ft_max(tab[0], tab[2]);
	if (min > ft_max(tab[1], tab[3]))
		min = ft_max(tab[1], tab[3]);
	if (min == ft_min(tab[0], tab[1]) + ft_min(tab[2], tab[3]))
	{
		if (tab[0] == ft_min(tab[0], tab[1]))
			tab[1] = 0;
		else
			tab[0] = 0;
		if (tab[2] == ft_min(tab[2], tab[3]))
			tab[3] = 0;
		else
			tab[2] = 0;
	}
	if (min == ft_max(tab[0], tab[2]))
		tab_zero(tab, 1, 3);
	if (min == ft_max(tab[1], tab[3]))
		tab_zero(tab, 0, 2);
}

static void	apply_all(int *tab, t_list **firsta, t_list **firstb)
{
	while (tab[0])
	{
		ft_ra(firsta);
		tab[0]--;
	}
	while (tab[1])
	{
		ft_rra(firsta);
		tab[1]--;
	}
	while (tab[2])
	{
		ft_rb(firstb);
		tab[2]--;
	}
	while (tab[3])
	{
		ft_rrb(firstb);
		tab[3]--;
	}
}

//// [ra, rra, rb, rrb]
void	apply_ops(int *tab, t_list **firsta, t_list **firstb)
{
	if (tab[0] && tab[2])
	{
		while (ft_min(tab[0], tab[2]))
		{
			ft_rr(firsta, firstb);
			tab[0]--;
			tab[2]--;
		}
	}
	if (tab[1] && tab[3])
	{
		while (ft_min(tab[1], tab[3]))
		{
			ft_rrr(firsta, firstb);
			tab[1]--;
			tab[3]--;
		}
	}
	apply_all(tab, firsta, firstb);
}
