/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:50:23 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:13:51 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_l_a_is_sorted(int *l_a)
{
	int i;

	i = 0;
	while (i < g_aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_l_a_is_complete_and_sorted(int *l_a, int items)
{
	int i;

	i = 0;
	if (g_aitems != items)
		return (0);
	while (i < g_aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_smallest_number(int *l_a)
{
	int i;
	int small;

	small = l_a[0];
	i = 1;
	while (i < g_aitems)
	{
		if (l_a[i] < small)
			small = l_a[i];
		i++;
	}
	return (small);
}

int		ft_find_its_position(int *l_a, int small)
{
	int i;

	i = 0;
	while (i < g_aitems)
	{
		if (l_a[i] == small)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_find_shortest_route_of_smallest_number(int *l_a)
{
	int small;
	int position;
	int route;

	small = ft_find_smallest_number(l_a);
	position = ft_find_its_position(l_a, small);
	if ((g_aitems % 2) == 0)
	{
		if (((g_aitems / 2) - 1) < position)
			route = 1;
		else
			route = 2;
	}
	else
	{
		if ((g_aitems / 2) == position)
			route = 0;
		else if ((g_aitems / 2) < position)
			route = 1;
		else
			route = 2;
	}
	return (route);
}
