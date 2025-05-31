/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sublists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:47:56 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/31 15:48:39 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_sublists(t_list **firsta, t_list **firstb, int maxrank,
		int minrank)
{
	int	rank;
	int	count;
	int	i;
	int	size;

	size = ft_lstsize(*firsta);
	count = 0;
	i = 0;
	while (*firsta && count < maxrank && i < size)
	{
		rank = ((t_elem *)(*firsta)->content)->rank;
		if (rank <= maxrank && rank > minrank)
		{
			ft_pb(firsta, firstb);
			count++;
		}
		else
			ft_ra(firsta);
		i++;
	}
}
