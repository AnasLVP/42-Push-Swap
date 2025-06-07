/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:24:21 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 17:03:21 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_list **firsta, int min)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *firsta;
	if (!temp)
		return ;
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

void	rotate_to_max(t_list **firstb, int max)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *firstb;
	if (!temp)
		return ;
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

void	sort_three(t_list **firsta)
{
	while (!ft_lstsorted(*firsta, 1))
	{
		if (((t_elem *)(*firsta)->content)->rank >
			((t_elem *)(*firsta)->next->content)->rank)
			ft_sa(firsta, 1);
		else
			ft_rra(firsta);
	}
	rotate_to_min(firsta, lst_min(*firsta));
}
