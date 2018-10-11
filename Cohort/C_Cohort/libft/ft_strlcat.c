/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 02:03:05 by tnyama            #+#    #+#             */
/*   Updated: 2018/05/30 02:40:05 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t i;

	d_len = (size_t)ft_strlen((char *)dst);
	s_len = (size_t)ft_strlen((char *)src);
	i = d_len;
	while ((*src) && ((d_len + 1) < size))
	{
		dst[d_len++] = *src++;
	}
	dst[d_len] = '\0';
	if (i > size)
		return (s_len + size);
	else
		return (s_len + i);
}
