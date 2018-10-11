/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:42:37 by tnyama            #+#    #+#             */
/*   Updated: 2018/06/14 01:54:25 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	read_to_store(int const fd, char **store)
{
	char	*buff;
	char	*temp;
	int		result;

	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	if (result > 0)
	{
		buff[result] = '\0';
		temp = ft_strjoin(*store, buff);
		free(*store);
		*store = temp;
	}
	free(buff);
	return (result);
}

int			get_next_line(int const fd, char **line)
{
	int			result;
	char		*end_of_line;
	static char	*store = NULL;

	if (!store)
		store = (char*)malloc(sizeof(*store));
	if (store == NULL || !line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((end_of_line = ft_strchr(store, '\n')) == NULL)
	{
		result = read_to_store(fd, &store);
		if (result == 0)
		{
			if (ft_strlen(store) == 0)
				return (0);
			store = ft_strjoin(store, "\n");
		}
		if (result < 0)
			return (-1);
	}
	*line = ft_strsub(store, 0, ft_strlen(store) - ft_strlen(end_of_line));
	store = ft_strdup(end_of_line + 1);
	return (1);
}
