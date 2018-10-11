/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:38:30 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:17:01 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_first_to_endb(int *l_a, t_pslist **ops)
{
	int temp;
	int i;

	if (g_bitems < 2)
		return ;
	i = 0;
	temp = l_a[0];
	while (i < g_bitems - 1)
	{
		l_a[i] = l_a[i + 1];
		i++;
	}
	l_a[g_bitems - 1] = temp;
	ft_add_to_list(ops, 7);
}

void	ft_recreate_origin(int *l_b)
{
	int i;

	i = 0;
	while (i < g_bitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(g_bitems)--;
}

void	ft_recreate_borigin(int *l_b)
{
	int i;

	i = 0;
	while (i < g_aitems - 1)
	{
		l_b[i] = l_b[i + 1];
		i++;
	}
	(g_aitems)--;
}

void	ft_pushb(int *l_a, int *l_b, t_pslist **ops)
{
	int	temp;
	int	temp2;
	int	i;

	if (!g_aitems)
		return ;
	if (g_bitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < g_bitems + 1)
		{
			if (i < g_bitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_borigin(l_b);
	(g_bitems)++;
	ft_add_to_list(ops, 5);
}

void	ft_push(int *l_a, int *l_b, t_pslist **ops)
{
	int	temp;
	int	temp2;
	int	i;

	if (!g_bitems)
		return ;
	if (g_aitems)
	{
		i = 1;
		temp = l_a[0];
		l_a[0] = l_b[0];
		while (i < g_aitems + 1)
		{
			if (i < g_aitems)
				temp2 = l_a[i];
			l_a[i] = temp;
			temp = temp2;
			i++;
		}
	}
	else
		l_a[0] = l_b[0];
	ft_recreate_origin(l_b);
	(g_aitems)++;
	ft_add_to_list(ops, 4);
}
