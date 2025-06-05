/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:09 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/05 15:14:23 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_list **first, int print)
{
	if (!*first)
		return ;
	if (!(*first)->next)
		return ;
	ft_lstswap(first);
	if (print)
		ft_printf("sa\n");
}

void	ft_sb(t_list **first, int print)
{
	if (!*first)
		return ;
	if (!(*first)->next)
		return ;
	ft_lstswap(first);
	if (print)
		ft_printf("sb\n");
}

void	ft_ss(t_list **firsta, t_list **firstb)
{
	ft_sa(firsta, 0);
	ft_sb(firstb, 0);
	ft_printf("ss\n");
}
