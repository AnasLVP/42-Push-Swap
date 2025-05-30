/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:00:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/30 17:07:48 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_list **first, char **av, int ac)
{
	int		i;
	t_list	*temp;
	int		*content;

	i = 1;
	while (i < ac)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(first, &free);
			return ;
		}
		*content = (int)ft_atoi(av[i]);
		temp = ft_lstnew(content);
		ft_lstadd_back(first, temp);
		i++;
	}
}

void	ft_lstswap(t_list **first)
{
	t_list	*second;

	if (!first || !*first || !(*first)->next)
		return ;
	second = (*first)->next;
	(*first)->next = second->next;
	if (second->next)
		second->next->previous = *first;
	second->previous = NULL;
	second->next = *first;
	(*first)->previous = second;
	*first = second;
}

int	ft_lstsorted(t_list **first)
{
	t_list	*tempfirst;

	tempfirst = *first;
	if (!tempfirst || !(tempfirst)->next)
		return (1);
	while (tempfirst->next)
	{
		if (*(int *)tempfirst->next->content < *(int *)tempfirst->content)
			return (0);
		tempfirst = tempfirst->next;
	}
	return (1);
}

t_list	*ft_lstmin(t_list **list)
{
	t_list	*temp;
	t_list	*res;

	temp = *list;
	res = temp;
	while (temp)
	{
		if (*(int *)temp->content < *(int *)res->content)
			res = temp;
		temp = temp->next;
	}
	return (res);
}

void	ft_lstnormalize(t_list **list)
{
	t_list	*temp;
	t_list	*first;
	int		num;
	int		size;

	first = *list;
	size = ft_lstsize(first);
	num = 0;
	while (num < size)
	{
		temp = ft_lstmin(list);
		*(int *)temp->content = num;
		num++;
	}
}
