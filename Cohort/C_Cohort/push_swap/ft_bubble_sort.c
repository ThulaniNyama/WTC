/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:49:04 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:13:15 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_tab_copy(int *copy, int *l_a)
{
	int i;

	i = 0;
	while (i < g_aitems)
	{
		copy[i] = l_a[i];
		i++;
	}
	return (copy);
}

void	ft_swap_2(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		*ft_bubble_sort(int *l_a)
{
	int	*copy;
	int i;
	int j;

	i = 0;
	copy = (int*)malloc(sizeof(*copy) * g_aitems);
	copy = ft_tab_copy(copy, l_a);
	while (i < g_aitems)
	{
		j = i + 1;
		while (j < g_aitems)
		{
			if (copy[j] < copy[i])
				ft_swap_2(&copy[i], &copy[j]);
			j++;
		}
		i++;
	}
	return (copy);
}
