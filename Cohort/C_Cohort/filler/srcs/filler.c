/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:48:09 by tnyama            #+#    #+#             */
/*   Updated: 2018/08/06 20:31:39 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"

void	place_piece(t_map_piece *info, t_player *me)
{
	init_place(info);
	while (info->p_y >= 0)
	{
		if (info->y_place - info->y_piece < 0)
		{
			info->place_ret = 2;
			return ;
		}
		info->m_x = info->x_place;
		info->p_x = info->x_piece - 1;
		while (info->p_x >= 0)
		{
			if (info->x_place - info->x_piece < 0)
			{
				info->place_ret = 1;
				return ;
			}
			if (info->piece[info->p_y][info->p_x--] != '.')
				info->temp_map[info->m_y][info->m_x] = me->my_shape;
			info->place_coordinate_x = info->m_x--;
			info->place_coordinate_y = info->m_y;
		}
		info->m_y--;
		info->p_y--;
	}
}

void	init_place(t_map_piece *info)
{
	info->p_y = info->y_piece - 1;
	info->m_y = info->y_place;
}

int		move(t_map_piece *info)
{
	if (info->place_ret == 1)
	{
		info->y_place--;
		info->x_place = info->x_cols - 1;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place--;
	return (0);
}

void	send_coordinate(t_map_piece *info)
{
	ft_putnbr(info->place_coordinate_y);
	ft_putchar(' ');
	ft_putnbr(info->place_coordinate_x);
	ft_putchar('\n');
	info->y_place = info->y_rows - 1;
}

int		main(void)
{
	t_player	*me;
	t_map_piece	*map_size;

	me = (t_player *)malloc(sizeof(*me));
	map_size = (t_map_piece *)malloc(sizeof(*map_size));
	algo_1(map_size, me);
	algo_4(map_size, me);
}
