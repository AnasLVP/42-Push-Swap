/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:00:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/30 18:14:48 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_list **first, char **av, int ac)
{
	int		i;
	t_list	*temp;
	t_elem	*content;

	i = 1;
	while (i < ac)
	{
		content = malloc(sizeof(t_elem));
		if (!content)
		{
			ft_lstclear(first, &free);
			return ;
		}
		content->value = (int)ft_atoi(av[i]);
		content->rank = 0;
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
	t_elem	*tempelem;
	t_elem	*nexttempelem;

	tempfirst = *first;
	if (!tempfirst || !(tempfirst)->next)
		return (1);
	while (tempfirst->next)
	{
		tempelem = tempfirst->content;
		nexttempelem = tempfirst->next->content;
		if (nexttempelem->value < tempelem->value)
			return (0);
		tempfirst = tempfirst->next;
	}
	return (1);
}

t_list	*ft_lstmin(t_list **list)
{
	t_list	*temp;
	t_list	*res;
	t_elem	*res_content;
	t_elem	*temp_content;

	temp = *list;
	temp_content = temp->content;
	while (temp_content->rank && temp->next)
	{
		temp = temp->next;
		temp_content = temp->content;
	}
	res = temp;
	while (temp)
	{
		res_content = res->content;
		temp_content = temp->content;
		if (temp_content->value < res_content->value && !temp_content->rank)
			res = temp;
		temp = temp->next;
	}
	return (res);
}

void	ft_lstnormalize(t_list **list)
{
	t_list	*temp;
	int		num;
	int		size;

	size = ft_lstsize(*list);
	num = 1;
	while (num <= size)
	{
		temp = ft_lstmin(list);
		((t_elem *)temp->content)->rank = num;
		num++;
	}
}
