/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:55:35 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 14:56:16 by aabouyaz         ###   ########.fr       */
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

static void	rotate_to_max(t_list **firstb, int max)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *firstb;
	while (temp)
	{
		if (((t_elem *)temp->content)->rank == max)
			break ;
		i++;
		temp = temp->next;
	}
	if (i < ft_lstsize(*firstb) / 2)
	{
		while (((t_elem *)(*firstb)->content)->rank != max)
			ft_rb(firstb);
	}
	else
	{
		while (((t_elem *)(*firstb)->content)->rank != max)
			ft_rrb(firstb);
	}
}

static void	push_back(t_list **firsta, t_list **firstb)
{
	int		i;
	int		size;

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
