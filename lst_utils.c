/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:00:29 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 18:19:42 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_list **first)
{
	(*first)->previous = (*first)->next;
	(*first)->next = (*first)->next->next;
	(*first)->previous->next = (*first);
	(*first)->previous->previous = NULL;
	(*first) = (*first)->previous;
}
