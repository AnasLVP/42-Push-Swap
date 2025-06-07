/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/07 17:17:07 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*	struct	*/
typedef struct s_elem
{
	int	value;
	int	rank;
}		t_elem;

/*	lists	*/
void	create_list(t_list **first, char **av, int ac);
int		lst_min(t_list *first);
int		lst_max(t_list *first);
void	ft_lstnormalize(t_list **list);
int		ft_lstsorted(t_list *first, int recurse);
void	ft_lstswap(t_list **first);
int		insert_index(t_list *firstb, int value);
void	rotate_to_max(t_list **firstb, int max);

/*	count operations	*/
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	total_ops(int *tab);
void	apply_ops(int *tab, t_list **firsta, t_list **firstb);
int		*operations(t_list *elem_a, t_list *firsta, t_list *firstb, int place);
int		min_operations(t_list *firsta, t_list *firstb);
void	rotatelists(t_list **firsta, t_list **firstb, int index);
void	sort_three(t_list **firsta);
void	rotate_to_min(t_list **firsta, int min);

/*	Push Swap Operations	*/
void	ft_sa(t_list **first, int print);
void	ft_sb(t_list **first, int print);
void	ft_ss(t_list **firsta, t_list **firstb);
void	ft_pb(t_list **firsta, t_list **firstb);
void	ft_pa(t_list **firsta, t_list **firstb);
void	ft_ra(t_list **firsta);
void	ft_rb(t_list **firstb);
void	ft_rr(t_list **firsta, t_list **firstb);
void	ft_rrb(t_list **firstb);
void	ft_rra(t_list **firsta);
void	ft_rrr(t_list **firsta, t_list **firstb);

/*	Parsing	*/
int		is_number(char *s);
int		only_uniques(char **av, int size);
int		parse_args(char **args);

void	push_swap(t_list **firsta, t_list **firstb);

#endif