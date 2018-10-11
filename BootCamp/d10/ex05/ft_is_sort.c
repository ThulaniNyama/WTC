/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:49:40 by tnyama            #+#    #+#             */
/*   Updated: 2018/04/24 08:50:20 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int is_sort;

	is_sort = 1;
	i = 0;
	while (i < length - 1 && is_sort == 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			is_sort = 0;
		i++;
	}
	if (is_sort == 1)
		return (1);
	is_sort = 1;
	i = 0;
	while (i < length - 1 && is_sort == 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			is_sort = 0;
		i++;
	}
	return (is_sort);
}
