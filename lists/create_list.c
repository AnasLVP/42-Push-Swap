/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:42:30 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/31 15:42:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
