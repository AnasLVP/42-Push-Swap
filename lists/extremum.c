/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:39:34 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 13:39:56 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_min(t_list *first)
{
	int		rank;
	t_list	*temp;
	int		min;

	temp = first;
	if (!temp)
		return (-1);
	min = ((t_elem *)temp->content)->rank;
	while (temp)
	{
		rank = ((t_elem *)temp->content)->rank;
		if (rank < min)
			min = rank;
		temp = temp->next;
	}
	return (min);
}

int	lst_max(t_list *first)
{
	int		rank;
	t_list	*temp;
	int		max;

	temp = first;
	if (!temp)
		return (-1);
	max = ((t_elem *)temp->content)->rank;
	while (temp)
	{
		rank = ((t_elem *)temp->content)->rank;
		if (rank > max)
			max = rank;
		temp = temp->next;
	}
	return (max);
}
