/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 19:01:32 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*	Parse Utils	*/
int	is_number(char *s);
int	only_uniques(char **av, int size);
int	parse_args(char **args);

/*	lists	*/
void	ft_lstswap(t_list **first);

/*	Push Swap	*/
void	ft_sa(t_list **first);
void	ft_sb(t_list **first);
void	ft_ss(t_list **firsta, t_list **firstb);
void	ft_pushb(t_list **firsta, t_list **firstb);
void	ft_pusha(t_list **firsta, t_list **firstb);


#endif