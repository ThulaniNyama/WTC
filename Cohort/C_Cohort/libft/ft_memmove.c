/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:12:11 by tnyama            #+#    #+#             */
/*   Updated: 2018/05/30 01:45:49 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (len <= 0)
		return (dst);
	if (sorc < dest)
	{
		while (len)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
		return (dest);
	}
	else
	{
		ft_memcpy(dst, src, len);
		return (dest);
	}
}
