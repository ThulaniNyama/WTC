/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 02:52:29 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/21 02:52:37 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*first_turn(t_env *env, t_room *room)
{
	char **pipe;

	if (!ft_strchr(env->line, '-') && env->line[0] != '#')
		ft_error();
	if (env->line[0] != '#')
	{
		pipe = ft_strsplit(env->line, '-');
		room = add_link(room, pipe[0], pipe[1]);
		room = add_link(room, pipe[1], pipe[0]);
		free(pipe[0]);
		free(pipe[1]);
		free(pipe);
	}
	ft_putendl(env->line);
	free(env->line);
	return (room);
}

void			nb_ants(t_env *env)
{
	if (get_next_line(0, &env->line) < 1)
		ft_error();
	if (!ft_strisdigit(env->line))
		ft_error();
	if ((env->nb_ant = ft_atoi(env->line)) < 1)
		ft_error();
	ft_putendl(env->line);
	free(env->line);
}

t_room			*parse_map(t_env *env, t_room *room)
{
	int	i;
	int	status;

	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, ' ') && env->line[0] != '#')
			break ;
		if (!ft_strcmp(env->line, "##start"))
			status = 1;
		if (!ft_strcmp(env->line, "##end"))
			status = 2;
		if (env->line[0] != '#')
		{
			i = ft_strchr(env->line, ' ') - env->line;
			room = add_room(room, env, i);
			if (status == 1)
				env->start = ft_strndup(env->line, i);
			if (status == 2)
				env->end = ft_strndup(env->line, i);
			status = 0;
		}
		ft_putendl(env->line);
		free(env->line);
	}
	return (room);
}

t_room			*parse_pipe(t_env *env, t_room *room)
{
	char **pipe;

	if (env->line)
		room = first_turn(env, room);
	while (get_next_line(0, &env->line) > 0)
	{
		if (!ft_strchr(env->line, '-') && env->line[0] != '#')
			break ;
		if (env->line[0] != '#')
		{
			pipe = ft_strsplit(env->line, '-');
			room = add_link(room, pipe[0], pipe[1]);
			room = add_link(room, pipe[1], pipe[0]);
			free(pipe[0]);
			free(pipe[1]);
			free(pipe);
		}
		ft_putendl(env->line);
		free(env->line);
	}
	return (room);
}
