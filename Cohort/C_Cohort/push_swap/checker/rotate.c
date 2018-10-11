/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:49:59 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/02 20:50:05 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"
#include <stdio.h>

void		ft_rotate(t_checker s)
{
	int tmp;
	int i;

	if (s.end == 0 || s.end == 1)
		return ;
	i = 0;
	tmp = s.num[0];
	while (i < s.end - 1)
	{
		s.num[i] = s.num[i + 1];
		i++;
		s.num[i] = tmp;
	}
}

void		ft_rotate_both(t_checker s, t_checker sb)
{
	ft_rotate(s);
	ft_rotate(sb);
}

void		ft_revrotate(t_checker s)
{
	int tmp;
	int i;

	if (s.end == 0 || s.end == 1)
		return ;
	i = s.end - 1;
	tmp = s.num[s.end - 1];
	while (i >= 0)
	{
		s.num[i] = s.num[i - 1];
		i--;
		s.num[i] = tmp;
	}
	s.num[0] = tmp;
}

void		ft_revrotate_both(t_checker s, t_checker sb)
{
	ft_revrotate(s);
	ft_revrotate(sb);
}
