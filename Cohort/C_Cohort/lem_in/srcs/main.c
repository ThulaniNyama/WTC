/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 02:52:11 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/21 02:52:19 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init(t_env *env)
{
	env->nb_ant = 0;
	env->start = NULL;
	env->end = NULL;
	env->weight = 0;
	env->poid_max = 0;
}

void		print_path(char **path, t_env *env)
{
	int		ant;
	int		room;

	ant = 1;
	ft_putchar('\n');
	while (ant <= env->nb_ant)
	{
		room = 0;
		while (path[room])
		{
			ft_putstr(ft_strjoin("L", ft_itoa(ant)));
			ft_putendl(ft_strjoin("-", path[room++]));
		}
		ant++;
	}
}

int			main(void)
{
	char	**path;
	t_env	env;
	t_room	*room;

	room = NULL;
	path = NULL;
	init(&env);
	nb_ants(&env);
	room = parse_map(&env, room);
	room = parse_pipe(&env, room);
	map_is_valid(&env);
	room = set_weights(&env, room);
	path = finding_path(&env, room, path, 0);
	print_path(path, &env);
	return (0);
}
