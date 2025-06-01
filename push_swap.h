/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/06/01 17:17:18 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*	Parsing	*/
int		is_number(char *s);
int		only_uniques(char **av, int size);
int		parse_args(char **args);

/*	lists	*/
void	ft_lstswap(t_list **first);
void	create_list(t_list **first, char **av, int ac);
int		ft_lstsorted(t_list *first, int recurse);
void	ft_lstnormalize(t_list **list);
void	push_sublists(t_list **firsta, t_list **firstb, int maxrank,
			int minrank);
int		lst_min(t_list *first);
int		lst_max(t_list *first);
void	rotate(void (*ra)(t_list **), void (*rra)(t_list **), t_list **first, int pos);
void	push_swap(t_list **firsta, t_list **firstb);

/*	struct	*/
typedef struct s_elem
{
	int	value;
	int	rank;
}		t_elem;

/*	Push Swap Operations	*/
void	ft_sa(t_list **first);
void	ft_sb(t_list **first);
void	ft_ss(t_list **firsta, t_list **firstb);
void	ft_pb(t_list **firsta, t_list **firstb);
void	ft_pa(t_list **firsta, t_list **firstb);
void	ft_ra(t_list **firsta);
void	ft_rb(t_list **firstb);
void	ft_rr(t_list **firsta, t_list **firstb);
void	ft_rrb(t_list **firstb);
void	ft_rra(t_list **firsta);
void	ft_rrr(t_list **firsta, t_list **firstb);

#endif