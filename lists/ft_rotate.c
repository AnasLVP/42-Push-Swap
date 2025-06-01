/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:12:49 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 17:17:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(void (*ra)(t_list **), void (*rra)(t_list **), t_list **first,
		int pos)
{
	int	i;

	if (pos <= ft_lstsize(*first) / 2)
	{
		i = 1;
		while (i < pos)
		{
			ra(first);
			i++;
		}
	}
	else
	{
		i = ft_lstsize(*first);
		while (i >= pos)
		{
			rra(first);
			i--;
		}
	}
}
