/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:40:58 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/31 15:41:31 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
