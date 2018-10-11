/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_route_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:51:45 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:14:30 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_second_small_number(int *l_a)
{
	int *copy;
	int i;
	int temp;

	copy = (int*)malloc(sizeof(*copy) * (g_aitems));
	i = 0;
	while (i < g_aitems)
	{
		copy[i] = l_a[i];
		i++;
	}
	copy = ft_bubble_sort(copy);
	temp = copy[1];
	free(copy);
	return (temp);
}

int		ft_next_is_in_formation(int *l_a, int next, int small)
{
	int i;
	int temp;
	int temp2;

	i = 0;
	while (i < g_aitems)
	{
		if (l_a[i] == next)
			temp = i;
		if (l_a[i] == small)
			temp2 = i;
		i++;
	}
	if (temp < temp2)
		return (1);
	return (0);
}

void	ft_execute_route_2(int *l_a, t_pslist **ops, int *l_b)
{
	int small;
	int next;

	small = ft_find_smallest_number(l_a);
	next = ft_find_second_small_number(l_a);
	while (!ft_smallest_is_first(l_a))
	{
		if (ft_next_is_in_formation(l_a, next, small))
		{
			if (l_a[0] == next && l_a[1] == small)
				ft_swap(l_a, ops);
			else
			{
				if (l_a[0] != next)
					ft_rotate_first_to_end(l_a, ops);
				else
					ft_swap(l_a, ops);
			}
		}
		else
			ft_rotate_first_to_end(l_a, ops);
	}
	if (!ft_l_a_is_sorted(l_a))
		ft_pushb(l_b, l_a, ops);
}
