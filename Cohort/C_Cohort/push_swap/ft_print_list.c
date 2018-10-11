/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 14:47:43 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 12:34:00 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_newline(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	ft_print_list_3(t_pslist *start)
{
	if (start->next && start->sort == 9 && (start->next)->sort == 10)
	{
		ft_putstr_newline("rrr");
		start = start->next;
	}
	else if (start->sort == 9 && start->next)
		ft_putstr_newline("rra");
	else if (start->sort == 9)
		ft_putstr("rra");
	else if (start->sort == 10 && start->next)
		ft_putstr_newline("rrb");
	else if (start->sort == 10)
		ft_putstr("rrb");
}

void	ft_print_list_2(t_pslist *start)
{
	if (start->sort == 4 && start->next)
		ft_putstr_newline("pa");
	else if (start->sort == 4)
		ft_putstr("pa");
	else if (start->sort == 5 && start->next)
		ft_putstr_newline("pb");
	else if (start->sort == 5)
		ft_putstr("pb");
	else if (start->next && start->sort == 6 && (start->next)->sort == 7)
	{
		ft_putstr_newline("rr");
		start = start->next;
	}
	else if (start->sort == 6 && start->next)
		ft_putstr_newline("ra");
	else if (start->sort == 6)
		ft_putstr("ra");
	else if (start->sort == 7 && start->next)
		ft_putstr_newline("rb");
	else if (start->sort == 7)
		ft_putstr("rb");
	else
		ft_print_list_3(start);
}

void	ft_print_list(t_pslist *list)
{
	t_pslist *start;

	start = list;
	while (start)
	{
		if (start->next && start->sort == 1 && (start->next)->sort == 2)
		{
			ft_putstr_newline("ss");
			start = start->next;
		}
		else if (start->sort == 1 && start->next)
			ft_putstr_newline("sa");
		else if (start->sort == 1)
			ft_putstr("sa");
		else if (start->sort == 2 && start->next)
			ft_putstr_newline("sb");
		else if (start->sort == 2)
			ft_putstr("sb");
		else
			ft_print_list_2(start);
		start = start->next;
	}
	ft_putchar('\n');
}
