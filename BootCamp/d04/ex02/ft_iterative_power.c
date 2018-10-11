/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 00:43:01 by tnyama            #+#    #+#             */
/*   Updated: 2018/04/14 01:10:34 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int temp;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (0);
	}
	else if (power == 1)
	{
		return (nb);
	}
	i = 1;
	temp = nb;
	while (i != power)
	{
		nb *= temp;
		i++;
	}
	return (nb);
}
