/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:11:07 by tnyama            #+#    #+#             */
/*   Updated: 2018/06/05 19:20:40 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int neg;
	int num;
	int lng;

	neg = 1;
	num = 0;
	lng = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v')
			|| (*str == '\f') || (*str == '\r') || (*str == '\n'))
		str++;
	if (*str == '-')
		neg = -1;
	if ((*str == '-' || *str == '+'))
		str++;
	while (ft_isdigit(*str))
	{
		num = ((num * 10) + (int)*str - '0');
		str++;
		lng++;
	}
	if (lng > 19)
		return ((num == -1) ? 0 : -1);
	return (num * neg);
}
