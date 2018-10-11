/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:42:07 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:18:52 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapb(int *l_a, t_pslist **ops)
{
	int	temp;

	if (g_bitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
	ft_add_to_list(ops, 2);
}

void	ft_swap(int *l_a, t_pslist **ops)
{
	int	temp;

	if (g_aitems < 2)
		return ;
	temp = l_a[0];
	l_a[0] = l_a[1];
	l_a[1] = temp;
	ft_add_to_list(ops, 1);
}
