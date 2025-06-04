/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:28:02 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/04 11:03:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_list **firsta)
{
	t_list	*last;

	if (*firsta)
	{
		last = ft_lstlast(*firsta);
		last->previous->next = NULL;
		last->previous = NULL;
		(*firsta)->previous = last;
		last->next = *firsta;
		*firsta = last;
	}
}

void	ft_rrb(t_list **firstb)
{
	t_list	*last;

	if (*firstb && (*firstb)->next)
	{
		last = ft_lstlast(*firstb);
		last->previous->next = NULL;
		last->previous = NULL;
		(*firstb)->previous = last;
		last->next = *firstb;
		*firstb = last;
	}
}

void	ft_rrr(t_list **firsta, t_list **firstb)
{
	ft_rra(firsta);
	ft_rrb(firstb);
}
