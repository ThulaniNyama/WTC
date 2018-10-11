/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:49:22 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/02 20:49:46 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

void		ft_push(t_checker *sa, t_checker *sb)
{
	int i;

	if (sa->end == 0)
		return ;
	i = sb->end - 1;
	while (i >= 0)
	{
		sb->num[i + 1] = sb->num[i];
		i--;
	}
	sb->num[0] = sa->num[0];
	sb->end++;
	while (i < sa->end)
	{
		sa->num[i] = sa->num[i + 1];
		i++;
	}
	sa->end--;
}
