/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:26:54 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/06 22:53:18 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//// [ra, rra, rb, rrb]
int	*operations(t_list *elem_a, t_list *firsta, t_list *firstb, int place)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * 4);
	if (!res)
		return (NULL);
	res[0] = place;
	res[1] = ft_lstsize(firsta) - place;
	res[2] = insert_index(firstb, ((t_elem *)(elem_a->content))->rank);
	res[3] = ft_lstsize(firstb) - res[2];
	return (res);
}

int	min_operations(t_list *firsta, t_list *firstb)
{
	int		i;
	int		res;
	int		min;
	int		*tab;
	t_list	*temp;

	i = 0;
	min = INT_MAX;
	temp = firsta;
	while (temp)
	{
		tab = operations(temp, firsta, firstb, i);
		total_ops(tab);
		if (min > (tab[0] + tab[1] + tab[2] + tab[3]))
		{
			min = (tab[0] + tab[1] + tab[2] + tab[3]);
			res = i;
		}
		free(tab);
		i++;
		temp = temp->next;
	}
	return (res);
}

void	rotatelists(t_list **firsta, t_list **firstb, int index)
{
	t_list	*temp;
	int		i;
	int		*tab;

	i = 0;
	temp = *firsta;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	tab = operations(temp, *firsta, *firstb, i);
	total_ops(tab);
	apply_ops(tab, firsta, firstb);
	free(tab);
	ft_pb(firsta, firstb);
}
