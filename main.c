/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/05 15:26:37 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*firsta;
	t_list	*firstb;

	firsta = NULL;
	firstb = NULL;
	if (ac == 1)
		return (0);
	if (!parse_args(av) || !only_uniques(av, ac - 1))
		return (write(2, "Error\n", 6));
	create_list(&firsta, av, ac);
	ft_lstnormalize(&firsta);
	ft_pb(&firsta, &firstb);
	ft_pb(&firsta, &firstb);
	while (firsta)
		rotatelists(&firsta, &firstb, (min_operations(firsta, firstb)));
	while (firstb)
		ft_pa(&firsta, &firstb);
	while (((t_elem *)firsta->content)->rank != lst_min(firsta))
		ft_ra(&firsta);
	if (firsta)
		ft_lstclear(&firsta, &free);
	if (firstb)
		ft_lstclear(&firstb, &free);
	return (0);
}
