/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnormalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:00:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 11:37:00 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_lstmin(t_list **list)
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
