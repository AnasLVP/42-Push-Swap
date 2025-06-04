/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/04 19:50:09 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_elem(void *cont)
{
	printf("value = %d et rank = %d\n", ((t_elem *)cont)->value,
		((t_elem *)cont)->rank);
	return ;
}

/////////////////////////////////////////////////////////////////////////////////

//// [ra, rra, rb, rrb]
int	*operations(t_list *elem_a, t_list *firsta, t_list *firstb, int place)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * 4);
	if (!res)
		return (NULL);
	res[0] = place;
	res[1] = ft_lstsize(firsta) - place;
	res[2] = insert_index(firstb, ((t_elem *)(elem_a->content))->rank);
	res[3] = ft_lstsize(firstb) - res[2];
	return (res);
}



void	rotatelist(t_list *firsta, t_list *firstb)
{
	int		i;
	int		z;
	int		*res;
	t_list	*temp;

	i = 0;
	temp = firsta;
	while (temp)
	{
		z = 0;
		res = operations(temp, firsta, firstb, i);
		while (z < 4)
		{
			printf("|%d|", res[z]);
			z++;
		}
		printf("minimum => %d\n", total_ops(res));
		z = 0;
		while (z < 4)
		{
			printf("|%d|", res[z]);
			z++;
		}
		printf("\n");
		free(res);
		i++;
		temp = temp->next;
	}
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
	ft_lstnormalize(&firsta);
	ft_pb(&firsta, &firstb);
	ft_pb(&firsta, &firstb);
	ft_pb(&firsta, &firstb);
	ft_pb(&firsta, &firstb);
	rotatelist(firsta, firstb);
	printf("---LISTE A---\n");
	ft_lstiter(firsta, &print_elem); // afficher la liste
	printf("-------------\n");
	// push_swap(&firsta, &firstb);
	// push_swap(&firsta, &firstb);
	printf("---LISTE B---\n");
	ft_lstiter(firstb, &print_elem); // afficher la liste
	printf("-------------\n");
	// // push_sublists(&firsta, &firstb, 10, 5);
	// printf("---LISTE B---\n");
	// ft_lstiter(firstb, &print_elem); // afficher la liste
	// printf("-------------\n");
	// printf("sorted= %d\n", ft_lstsorted(firsta, 1));
	// printf("INSERT =c %d\n", insert_index(firsta, 2));
	// printf("----RESULT----\n");
	// ft_lstiter(firsta, &print_elem); // afficher la liste
	// printf("--------------\n");
	ft_lstclear(&firsta, &free); // free la liste
	if (firstb)
		ft_lstclear(&firstb, &free); // free la liste
	return (0);
}
