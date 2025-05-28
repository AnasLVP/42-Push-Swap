/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:00:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 19:35:18 by aabouyaz         ###   ########.fr       */
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
	(*first)->previous = (*first)->next;
	(*first)->next = (*first)->next->next;
	(*first)->previous->next = (*first);
	(*first)->previous->previous = NULL;
	(*first) = (*first)->previous;
}
