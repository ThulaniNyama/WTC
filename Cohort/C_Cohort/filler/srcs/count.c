/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:47:37 by tnyama            #+#    #+#             */
/*   Updated: 2018/08/06 16:47:43 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"

void	get_shape_num_p(t_map_piece *p_info)
{
	int x;
	int y;
	int shapes;

	y = 0;
	shapes = 0;
	while (y < p_info->y_piece)
	{
		x = 0;
		while (x < p_info->x_piece)
		{
			if (p_info->piece[y][x] == '*')
				shapes++;
			x++;
		}
		y++;
	}
	p_info->add_num = shapes;
}

void	get_os_xs_num(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->y_rows)
	{
		x = 0;
		while (x < p_info->x_cols)
		{
			if (p_info->map[y][x] == 'O' || p_info->map[y][x] == 'o')
				os++;
			else if (p_info->map[y][x] == 'X' || p_info->map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->os_num = os;
	p_info->xs_num = xs;
}

void	get_temp_os_xs(t_map_piece *p_info)
{
	int x;
	int y;
	int os;
	int xs;

	y = 0;
	os = 0;
	xs = 0;
	while (y < p_info->y_rows)
	{
		x = 0;
		while (x < p_info->x_cols)
		{
			if (p_info->temp_map[y][x] == 'O' || p_info->temp_map[y][x] == 'o')
				os++;
			else if (p_info->temp_map[y][x] == 'X' ||
					p_info->temp_map[y][x] == 'x')
				xs++;
			x++;
		}
		y++;
	}
	p_info->temp_os = os;
	p_info->temp_xs = xs;
}

int		check_placement(t_map_piece *p_info, t_player *shape)
{
	if (shape->my_shape == 'O')
	{
		if ((p_info->os_num + p_info->add_num - 1) == p_info->temp_os &&
				(p_info->xs_num == p_info->temp_xs))
			return (0);
		else
			return (1);
	}
	else if (shape->my_shape == 'X')
	{
		if ((p_info->xs_num + p_info->add_num - 1) == p_info->temp_xs &&
				(p_info->os_num == p_info->temp_os))
			return (0);
		else
			return (1);
	}
	return (-1);
}

void	copy_tmp_map(t_map_piece *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(info->temp_map = (char**)malloc(sizeof(char *) * info->y_rows)))
		return ;
	while (y < info->y_rows)
	{
		x = 0;
		info->temp_map[y] = (char *)malloc(sizeof(char) * info->x_cols);
		while (x < info->x_cols)
		{
			info->temp_map[y][x] = info->map[y][x];
			x++;
		}
		y++;
	}
}
