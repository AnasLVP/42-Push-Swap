/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:47:56 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/04 19:37:12 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_pos(t_list *first, int rank)
{
	t_list	*temp;
	int		actual;
	int		res;

	res = 1;
	temp = first;
	while (temp)
	{
		actual = ((t_elem *)temp->content)->rank;
		if (actual == rank)
			return (res);
		res++;
		temp = temp->next;
	}
	return (-1);
}

int	insert_index(t_list *firstb, int value)
{
	int		res;
	int		rank;
	int		next_rank;
	t_list	*temp;

	res = 1;
	temp = firstb;
	if (value < lst_min(firstb))
		return (get_pos(firstb, lst_min(firstb)));
	if (value > lst_max(firstb))
	{
		if (get_pos(firstb, lst_max(firstb)) <= 0)
			return (0);
		return (get_pos(firstb, lst_max(firstb)) - 1);
	}
	while (temp->next)
	{
		rank = ((t_elem *)temp->content)->rank;
		next_rank = ((t_elem *)temp->next->content)->rank;
		if (value < rank && value > next_rank)
			return (res);
		res++;
		temp = temp->next;
	}
	return (0);
}
