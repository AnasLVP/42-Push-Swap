/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:09 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/29 17:38:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_list **first)
{
	if (!*first)
		return ;
	if (!(*first)->next)
		return ;
	ft_lstswap(first);
}

void	ft_sb(t_list **first)
{
	if (!*first)
		return ;
	if (!(*first)->next)
		return ;
	ft_lstswap(first);
}

void	ft_ss(t_list **firsta, t_list **firstb)
{
	ft_sa(firsta);
	ft_sb(firstb);
}
