/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 01:42:16 by tnyama            #+#    #+#             */
/*   Updated: 2018/05/30 01:42:33 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *x;
	char *y;

	if (n == 0 || dst == src)
		return (dst);
	x = (char *)dst;
	y = (char *)src;
	while (--n)
		*x++ = *y++;
	*x = *y;
	return (dst);
}
