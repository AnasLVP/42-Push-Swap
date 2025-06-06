/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:17:30 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/06 20:17:08 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_list **firsta)
{
	t_list	*temp;

	if (*firsta && (*firsta)->next)
	{
		temp = *firsta;
		*firsta = temp->next;
		(*firsta)->previous = NULL;
		temp->next = NULL;
		ft_lstadd_back(firsta, temp);
	}
	ft_printf("ra\n");
}

void	ft_rb(t_list **firstb)
{
	t_list	*temp;

	if (*firstb && (*firstb)->next)
	{
		temp = *firstb;
		*firstb = temp->next;
		(*firstb)->previous = NULL;
		temp->next = NULL;
		ft_lstadd_back(firstb, temp);
	}
	ft_printf("rb\n");
}

void	ft_rr(t_list **firsta, t_list **firstb)
{
	t_list	*temp;

	if (*firsta && (*firsta)->next)
	{
		temp = *firsta;
		*firsta = temp->next;
		(*firsta)->previous = NULL;
		temp->next = NULL;
		ft_lstadd_back(firsta, temp);
	}
	if (*firstb && (*firstb)->next)
	{
		temp = *firstb;
		*firstb = temp->next;
		(*firstb)->previous = NULL;
		temp->next = NULL;
		ft_lstadd_back(firstb, temp);
	}
	ft_printf("rr\n");
}
