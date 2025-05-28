/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/28 13:59:52 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Parse Utils
int	is_number(char *s);
int	only_uniques(char **av, int size);
int	parse_args(char **args);

// Push Swap
int	*make_astack(char **args, int size);

#endif