/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sublists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:47:56 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 17:34:57 by aabouyaz         ###   ########.fr       */
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

static int	insert_index(t_list *firstb, int value)
{
	int		res;
	int		rank;
	int		next_rank;
	t_list	*temp;

	res = 1;
	temp = firstb;
	if (value < lst_min(firstb))
		return (get_pos(firstb, lst_min(firstb)) + 1);
	if (value > lst_max(firstb))
	{
		if (get_pos(firstb, lst_max(firstb)) <= 0)
			return (0);
		return (get_pos(firstb, lst_max(firstb)));
	}
	while (temp->next)
	{
		rank = ((t_elem *)temp->content)->rank;
		next_rank = ((t_elem *)temp->next->content)->rank;
		if (value < rank && value > next_rank)
			return (res + 1);
		res++;
		temp = temp->next;
	}
	return (0);
}

static void	insert_b(t_list **firstb, int rank)
{
	int	j;
	int	index;

	index = insert_index(*firstb, rank);
	j = 0;
	if (!*firstb || ft_lstsize(*firstb) == 1)
		return ;
	while (j < index - 1)
	{
		ft_rb(firstb);
		j++;
	}
}

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
			insert_b(firstb, rank);
			ft_pb(firsta, firstb);
			count++;
		}
		else
			ft_ra(firsta);
		i++;
	}
}

void	push_swap(t_list **firsta, t_list **firstb)
{
	int	sublist_size;
	int	index;
	int	rotation;

	sublist_size = ft_lstsize(*firsta) / 10;
	index = sublist_size;
	ft_lstnormalize(firsta);
	while (*firsta && !ft_lstsorted(*firsta, 1))
	{
		push_sublists(firsta, firstb, index, index - sublist_size);
		index = index + sublist_size;
		while (get_pos(*firstb, lst_max(*firstb)) != 1)
			rotate(&ft_rb, &ft_rrb, firstb, get_pos(*firstb, lst_max(*firstb)));
		while (*firstb)
			ft_pa(firsta, firstb);
		rotation = 0;
		while (rotation < sublist_size)
		{
			ft_ra(firsta);
			rotation++;
		}
	}
	while (get_pos(*firsta, lst_min(*firsta)) != 1)
		rotate(&ft_ra, &ft_rra, firstb, get_pos(*firstb, lst_min(*firsta)));
}
