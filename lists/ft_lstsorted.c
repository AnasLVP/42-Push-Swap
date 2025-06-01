/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:43:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 11:37:07 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsorted(t_list *first, int recurse)
{
	t_list	*next;
	int		elem;
	int		nextelem;
	int		firstvalue;

	firstvalue = ((t_elem *)(first)->content)->value;
	while (first->next)
	{
		elem = ((t_elem *)first->content)->value;
		next = first->next;
		nextelem = ((t_elem *)next->content)->value;
		if (next && nextelem < elem)
		{
			if (recurse && ft_lstsorted(next, 0)
				&& firstvalue > ((t_elem *)ft_lstlast(next)->content)->value)
				return (1);
			return (0);
		}
		first = next;
	}
	return (1);
}
