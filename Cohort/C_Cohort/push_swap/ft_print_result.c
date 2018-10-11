/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:37:40 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/03 11:16:21 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_result(int *l_a, int items)
{
	int i;

	i = 0;
	while (i < items)
	{
		ft_putnbr(l_a[i]);
		if (i < items - 1)
			ft_putchar(' ');
		i++;
	}
}
