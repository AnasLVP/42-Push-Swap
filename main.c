/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 19:12:30 by aabouyaz         ###   ########.fr       */
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

void	printlist(void *cont)
{
	printf("%d\n", *(int *)cont);
	return ;
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
	create_list(&firsta, av, ac);
	ft_lstiter(firsta, &printlist);
	ft_lstclear(&firsta, &free);
	return (0);
}
