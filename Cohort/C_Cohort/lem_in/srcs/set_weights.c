/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_weights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 02:52:47 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/21 02:52:53 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*set_end_weight(t_env *env, t_room *room)
{
	t_room		*tmp;
	t_linkroom	*tmp2;

	tmp = room;
	tmp2 = room->link;
	while (ft_strcmp(tmp->name, env->end))
		tmp = tmp->next;
	if (!tmp->link)
		ft_error();
	env->weight = 1;
	tmp->poid = 1;
	env->poid_max = 1;
	return (room);
}

static t_room	*set_unlinked_room(t_env *env, t_room *room)
{
	t_room		*tmp;

	tmp = room;
	if (env->poid_max >= env->nb_room + 10)
		ft_error();
	while (tmp)
	{
		if (tmp->poid == 0)
			env->weight++;
		if (tmp->poid == -1 || tmp->poid == 0)
			tmp->poid = env->poid_max + 1;
		tmp = tmp->next;
	}
	return (room);
}

t_room			*set_weights(t_env *env, t_room *room)
{
	t_room		*tmp;

	room = set_end_weight(env, room);
	while (env->weight < env->nb_room && env->poid_max < env->nb_room + 10)
	{
		tmp = room;
		while (tmp)
		{
			if (!tmp->link && !tmp->poid)
			{
				env->weight++;
				tmp->poid = -1;
			}
			else if (!tmp->poid)
				tmp = set_weights2(env, tmp);
			if (!ft_strcmp(tmp->name, env->start) && tmp->poid > 0)
				room = set_unlinked_room(env, room);
			tmp = tmp->next;
		}
		env->poid_max++;
	}
	return (room);
}

t_room			*set_weights2(t_env *env, t_room *room)
{
	t_linkroom	*tmp;

	tmp = room->link;
	while (tmp && tmp->room->poid != env->poid_max)
		tmp = tmp->next;
	if (!tmp)
		return (room);
	room->poid = env->poid_max + 1;
	env->weight++;
	return (room);
}
