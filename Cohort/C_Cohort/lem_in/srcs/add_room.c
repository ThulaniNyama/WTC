/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 02:49:38 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/21 02:49:50 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 02:49:34 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/21 02:49:34 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*add_room(t_room *room, t_env *env, int i)
{
	t_room	*new_room;
	t_room	*tmp;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		ft_error();
	env->nb_room++;
	new_room->name = ft_strndup(env->line, i);
	new_room->link = NULL;
	new_room->next = NULL;
	new_room->poid = 0;
	if (!room)
		return (new_room);
	else
	{
		tmp = room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
		return (room);
	}
}

t_room	*add_link(t_room *room, char *src, char *dst)
{
	t_linkroom	*new;
	t_linkroom	*tmp_link;
	t_room		*tmp;
	t_room		*tmp2;

	if (!(tmp2 = find_room(dst, room)) || !ft_strcmp(src, dst))
		ft_error();
	if (!(tmp = find_room(src, room)))
		ft_error();
	if (!(new = (t_linkroom *)malloc(sizeof(t_room))))
		ft_error();
	new->room = tmp2;
	new->next = NULL;
	if (!tmp->link)
		tmp->link = new;
	else
	{
		tmp_link = tmp->link;
		while (tmp_link->next)
			tmp_link = tmp_link->next;
		tmp_link->next = new;
	}
	return (room);
}
