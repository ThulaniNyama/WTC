/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 04:23:32 by tnyama            #+#    #+#             */
/*   Updated: 2018/05/30 02:43:55 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	len2;
	int		result;

	len = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	len = (len <= len2) ? len + 1 : len2 + 1;
	len = (len <= n) ? len : n;
	result = ft_memcmp(s1, s2, len);
	return (result);
}
