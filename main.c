/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/31 16:01:30 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_elem(void *cont)
{
	printf("value = %d et rank = %d\n", ((t_elem *)cont)->value, ((t_elem *)cont)->rank);
	return ;
}

/////////////////////////////////////////////////////////////////////////////////

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
		
	create_list(&firsta, av, ac); // creer la liste
	printf("---LISTE A---\n");
	ft_lstiter(firsta, &print_elem); // afficher la liste
	printf("-------------\n");
	
	// printf("insertion = %d\n", insert_index(firsta, 3));
	// ft_lstnormalize(&firsta);
	// push_sublists(&firsta, &firstb, 5, 0);

	// // push_swap(&firsta, &firstb);
	// printf("---LISTE B---\n");
	// ft_lstiter(firstb, &print_elem); // afficher la liste
	// printf("-------------\n");
	// push_sublists(&firsta, &firstb, 10, 5);
	// printf("---LISTE B---\n");
	// ft_lstiter(firstb, &print_elem); // afficher la liste
	// printf("-------------\n");
	
	printf("sorted= %d\n", ft_lstsorted(firsta, 1));

	printf("----RESULT----\n");
	ft_lstiter(firsta, &print_elem); // afficher la liste
	printf("--------------\n");
	
	ft_lstclear(&firsta, &free); // free la liste
	if (firstb)
		ft_lstclear(&firstb, &free); // free la liste
	return (0);
}
