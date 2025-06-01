/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:56:42 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 17:08:05 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_list **firsta, t_list **firstb)
{
	t_list	*temp;

	temp = (*firstb);
	if (*firstb)
	{
		(*firstb) = (*firstb)->next;
		ft_lstadd_front(firsta, temp);
	}
	printf("pa\n");
}

void	ft_pb(t_list **firsta, t_list **firstb)
{
	t_list	*temp;

	temp = (*firsta);
	if (*firsta)
	{
		(*firsta) = (*firsta)->next;
		ft_lstadd_front(firstb, temp);
	}
	printf("pb\n");
}
