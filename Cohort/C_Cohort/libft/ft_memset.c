/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:32:59 by tnyama            #+#    #+#             */
/*   Updated: 2018/05/30 04:57:27 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *i;

	if (n == 0)
		return (b);
	i = (unsigned char *)b;
	while (n--)
	{
		*i = (unsigned char)c;
		if (n)
			i++;
	}
	return (b);
}
