/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_decreasing_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:39:17 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:18:19 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_decreasing_list(int *l_a, t_pslist **ops, int *l_b)
{
	int items;

	items = g_aitems;
	while (!ft_l_a_is_complete_and_sorted(l_a, items))
	{
		if (g_aitems == 3)
		{
			ft_rotate_first_to_end(l_a, ops);
			ft_swap(l_a, ops);
		}
		while (!ft_l_a_is_sorted(l_a))
		{
			while (g_aitems > 4)
				ft_pushb(l_b, l_a, ops);
			ft_swap(l_a, ops);
			ft_rotate_first_to_end(l_a, ops);
			ft_rotate_first_to_end(l_a, ops);
			ft_swap(l_a, ops);
		}
		if (!ft_l_a_is_complete_and_sorted(l_a, items))
		{
			ft_push(l_a, l_b, ops);
			ft_rotate_first_to_end(l_a, ops);
		}
	}
}

int		ft_l_a_is_sorted_decreasing(int *l_a)
{
	int i;
	int start;

	i = 0;
	start = l_a[0];
	while (i < g_aitems)
	{
		if (l_a[i] > start)
			return (0);
		start = l_a[i];
		i++;
	}
	return (1);
}
