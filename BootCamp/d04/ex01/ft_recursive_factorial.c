/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 00:36:24 by tnyama            #+#    #+#             */
/*   Updated: 2018/04/14 00:40:45 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 12)
	{
		return (0);
	}
	else if (nb < 3)
	{
		return (nb);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
