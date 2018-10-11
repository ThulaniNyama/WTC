/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:30:46 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:14:52 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_unsorted(int *l_a)
{
	int i;
	int ok;
	int *sorted;

	i = 0;
	ok = 0;
	sorted = ft_bubble_sort(l_a);
	while (i < g_aitems)
	{
		if (l_a[i] == sorted[i])
			ok++;
		else
			break ;
		i++;
	}
	free(sorted);
	return (g_aitems - ok);
}

int		ft_other_than_first_two_list_is_sorted(int *l_a)
{
	int i;

	i = 2;
	while (i < g_aitems - 1)
	{
		if (l_a[i] > l_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_execute_operations_case_x(int *l_a, t_pslist **ops)
{
	ft_swap(l_a, ops);
	ft_rotate_first_to_end(l_a, ops);
	ft_rotate_first_to_end(l_a, ops);
}

void	ft_execute_operations_case_y(int *l_a, t_pslist **ops, int *l_b)
{
	ft_push(l_a, l_b, ops);
	ft_rotate_first_to_end(l_a, ops);
}

void	ft_solve_case_special(int *l_a, t_pslist **ops, int *l_b, int items)
{
	int unsorted;

	unsorted = ft_count_unsorted(l_a);
	while (!ft_l_a_is_complete_and_sorted(l_a, items))
	{
		while (!ft_l_a_is_sorted(l_a))
		{
			while (!ft_biggest_is_first(l_a))
			{
				ft_rotate_last_to_start(l_a, ops);
				g_count++;
			}
			if (unsorted == g_count && l_a[0] > l_a[1] &&
					ft_other_than_first_two_list_is_sorted(l_a))
				ft_execute_operations_case_x(l_a, ops);
			else
			{
				ft_pushb(l_b, l_a, ops);
				g_count--;
				unsorted--;
			}
		}
		if (!ft_l_a_is_complete_and_sorted(l_a, items))
			ft_execute_operations_case_y(l_a, ops, l_b);
	}
}
