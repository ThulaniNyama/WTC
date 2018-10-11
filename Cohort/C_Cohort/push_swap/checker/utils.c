/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:50:35 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/02 20:51:01 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

void		ft_error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int			ft_check_order(t_checker stack_a, t_checker stack_b)
{
	int		tmp;
	int		i;

	i = 1;
	if (stack_b.end != 0)
		return (0);
	tmp = stack_a.num[0];
	while (i < stack_a.end)
	{
		if (stack_a.num[i] < tmp)
			return (0);
		tmp = stack_a.num[i];
		i++;
	}
	return (1);
}

void		print_stack(t_checker a, t_checker b, int yes)
{
	int i;

	if (yes)
	{
		i = 0;
		ft_putstr("STACK A:\n");
		while (i < a.end)
		{
			ft_putnbr(a.num[i++]);
			ft_putchar('\n');
		}
		i = 0;
		ft_putstr("STACK B:\n");
		while (i < b.end)
		{
			ft_putnbr(b.num[i++]);
			ft_putchar('\n');
		}
		ft_putnbr(a.end);
		ft_putstr(" elements are currently in stack A, and <");
		ft_putnbr(b.end);
		ft_putstr("> elements in stack B\n\nEnter command:\n--------------\n");
	}
}
