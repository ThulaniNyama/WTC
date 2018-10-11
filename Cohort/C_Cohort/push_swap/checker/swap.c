/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:50:17 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/02 20:50:29 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void		ft_swap(t_checker s)
{
	if (s.end == 0 || s.end == 1)
		return ;
	(s.num[0] ^= s.num[1]);
	(s.num[1] ^= s.num[0]);
	(s.num[0] ^= s.num[1]);
}

void		ft_swap_both(t_checker s, t_checker sb)
{
	ft_swap(s);
	ft_swap(sb);
}
