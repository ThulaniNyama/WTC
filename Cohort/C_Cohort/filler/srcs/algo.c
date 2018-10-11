/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:47:04 by tnyama            #+#    #+#             */
/*   Updated: 2018/08/06 16:47:12 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"

void	init_struct(t_map_piece *info)
{
	info->x_place = 0;
	info->y_place = 0;
	info->place_ret = 0;
	info->add_num = 0;
	info->os_num = 0;
	info->xs_num = 0;
	info->temp_os = 0;
	info->temp_xs = 0;
	info->place_coordinate_x = 0;
	info->place_coordinate_y = 0;
}

void	algo_1(t_map_piece *info, t_player *me)
{
	init_player(me);
	m_size(info);
	read_map(info);
	info->place_ret = 0;
	piece_size(info);
	read_piece(info);
	copy_tmp_map(info);
}

void	algo_2(t_map_piece *info, t_player *me)
{
	copy_tmp_map(info);
	get_shape_num_p(info);
	info->place_ret = 0;
	place_piece(info, me);
	get_os_xs_num(info);
	get_temp_os_xs(info);
}

void	algo_3(t_map_piece *info)
{
	free(info->map);
	read_map(info);
	info->x_piece = 0;
	info->y_piece = 0;
	piece_size(info);
	free(info->piece);
	read_piece(info);
}

void	algo_4(t_map_piece *info, t_player *me)
{
	info->rd = 0;
	while (1)
	{
		algo_2(info, me);
		if (!(check_placement(info, me)))
		{
			send_coordinate(info);
			if (info->rd > 0)
				algo_3(info);
		}
		else
		{
			if (!move(info))
			{
				copy_tmp_map(info);
				info->rd++;
			}
			else
			{
				ft_putendl("0 0");
				return ;
			}
		}
	}
}
