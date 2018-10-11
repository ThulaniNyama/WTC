/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:38:01 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 13:23:09 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_last_to_startb(int *l_a, t_pslist **ops)
{
	int temp;
	int	i;

	if (g_bitems < 2)
		return ;
	temp = l_a[g_bitems - 1];
	i = g_bitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
	ft_add_to_list(ops, 10);
}

void	ft_rotate_last_to_start(int *l_a, t_pslist **ops)
{
	int temp;
	int	i;

	if (g_aitems < 2)
		return ;
	temp = l_a[g_aitems - 1];
	i = g_aitems - 1;
	while (i > 0)
	{
		l_a[i] = l_a[i - 1];
		i--;
	}
	l_a[0] = temp;
	ft_add_to_list(ops, 9);
}

void	ft_execute_case_3_numbers(int *l_a, t_pslist **ops)
{
	ft_swap(l_a, ops);
	ft_rotate_first_to_end(l_a, ops);
}

void	ft_solve_case_standard(int *l_a, t_pslist **ops, int *l_b)
{
	int route;

	route = ft_find_shortest_route_of_smallest_number(l_a);
	if (route == 1)
		ft_execute_route_1(l_a, ops, l_b);
	else
		ft_execute_route_2(l_a, ops, l_b);
}

void	ft_push_swap(int *s_a, int len, int *s_b, t_pslist **sort)
{
	g_aitems = sort;
	if (ft_nbr_of_sorted_is_bigger_than_unsorted(s_a))
		ft_solve_case_special(s_a, sort, s_b, len);
	else if (ft_l_a_is_sorted_decreasing(s_a) && len > 2)
		ft_solve_decreasing_list(s_a, sort, s_b);
	else
	{
		while (!ft_l_a_is_complete_and_sorted(s_a, len))
		{
			while (!ft_l_a_is_sorted(s_a))
			{
				if (g_aitems == 3 && s_a[0] < s_a[1] && s_a[1] > s_a[2] &&
						s_a[0] < s_a[2])
					ft_execute_case_3_numbers(s_a, sort);
				else
					ft_solve_case_standard(s_a, sort, s_b);
			}
			if (!ft_l_a_is_complete_and_sorted(s_a, len))
				ft_push(s_a, s_b, sort);
		}
	}
}
