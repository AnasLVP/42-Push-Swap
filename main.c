/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/30 17:08:05 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(void *cont)
{
	printf("%d\n", *(int *)cont);
	return ;
}

/////////////////////////////////////////////////////////////////////////////////

int	insert_index(t_list *firstb, int value)
{
	int		res;
	t_list	*temp;
	t_list	*tempnext;

	res = 1;
	temp = firstb;
	while (temp)
	{
		tempnext = temp->next;
		if (tempnext)
		{
			if (value <= *(int *)temp->content && value >= *(int *)tempnext->content)
				return (res + 1);
		}
		else if (value <= *(int *)temp->content)
			return (res + 1);
		res++;
		temp = tempnext;
	}
	return (0);
}

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
	ft_lstiter(firsta, &printlist); // afficher la liste
	printf("-------------\n");
	
	// printf("insertion = %d\n", insert_index(firsta, 3));
	
	// push_swap(&firsta, &firstb);

	printf("---LISTE B---\n");
	ft_lstiter(firstb, &printlist); // afficher la liste
	printf("-------------\n");
	
	// printf("minimum = %d", *(int *)ft_lstmin(&firsta)->content);
	ft_lstnormalize(&firsta);
	
	printf("----RESULT----\n");
	ft_lstiter(firsta, &printlist); // afficher la liste
	printf("--------------\n");
	
	ft_lstclear(&firsta, &free); // free la liste
	if (firstb)
		ft_lstclear(&firstb, &free); // free la liste
	return (0);
}
