/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:48:29 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 11:05:25 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_list(t_pslist **start, int s)
{
	t_pslist	*new;
	t_pslist	*list;

	new = (t_pslist*)malloc(sizeof(*new));
	new->sort = s;
	new->next = NULL;
	list = *start;
	if (list == NULL)
		*start = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
