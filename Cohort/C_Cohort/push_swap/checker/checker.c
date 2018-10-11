/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:47:41 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 13:10:59 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include "checker.h"

int				num_val(char **arg, int count)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (i < count)
	{
		if (ft_isdigit(arg[i][j]) == 0 && arg[i][j] != ' '
				&& arg[i][j] != '+' && arg[i][j] != '-')
			return (0);
		j++;
		if (!arg[i][j])
		{
			i++;
			j = 0;
		}
	}
	return (1);
}

int				dup_check(long *num, int end)
{
	int i;
	int j;

	j = 1;
	i = 0;
	while (i < end - 1)
	{
		if (num[i] == num[j])
			return (1);
		j++;
		if (j == end)
		{
			i++;
			j = i + 1;
		}
	}
	return (0);
}

t_checker		array_maker(char **av, int ac)
{
	t_savespace	h;

	h.k = 0;
	h.i = 1;
	h.j = 0;
	h.array.num = (long*)malloc(sizeof(long) * 2000);
	while (h.i < ac)
	{
		if (av[h.i][h.j] == ' ')
			h.j++;
		else
		{
			h.array.num[h.k] = ft_atoi(av[h.i] + h.j);
			while (av[h.i][h.j] != ' ' && av[h.i][h.j])
				h.j++;
			h.k++;
		}
		if (!av[h.i][h.j])
		{
			h.j = 0;
			h.i++;
		}
	}
	h.array.end = h.k;
	return (h.array);
}

int				overflow_check(long *numbers, int k)
{
	while (k >= 0)
	{
		if (numbers[k] > 2147483647 || numbers[k] < -2147483648)
			return (1);
		k--;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_save	a;

	a.b.num = (long*)malloc(sizeof(long) * 2000);
	a.b.end = 0;
	if (num_val(av, ac) == 0)
		ft_error_msg();
	a.a = array_maker(av, ac);
	if (overflow_check(a.a.num, a.a.end - 1) == 1
			|| dup_check(a.a.num, a.a.end) == 1)
		ft_error_msg();
	a.ret = 1;
	while (a.ret)
	{
		a.ret = get_next_line(0, &a.str);
		if (!a.ret)
			break ;
		do_op(get_op(a.str), &a.a, &a.b);
		free(a.str);
	}
	ft_check_order(a.a, a.b) == 0 ? ft_putstr("KO\n") : ft_putstr("OK\n");
}
