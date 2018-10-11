/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:48:06 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 13:10:07 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"
#include <stdio.h>

int		get_op(char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		return (1);
	else if (ft_strcmp(op, "sb") == 0)
		return (2);
	else if (ft_strcmp(op, "ss") == 0)
		return (3);
	else if (ft_strcmp(op, "pa") == 0)
		return (4);
	else if (ft_strcmp(op, "pb") == 0)
		return (5);
	else if (ft_strcmp(op, "ra") == 0)
		return (6);
	else if (ft_strcmp(op, "rb") == 0)
		return (7);
	else if (ft_strcmp(op, "rr") == 0)
		return (8);
	else if (ft_strcmp(op, "rra") == 0)
		return (9);
	else if (ft_strcmp(op, "rrb") == 0)
		return (10);
	else if (ft_strcmp(op, "rrr") == 0)
		return (11);
	else
		return (12);
}

void	do_op(int i, t_checker *stack_a, t_checker *stack_b)
{
	if (i == 1)
		ft_swap(*stack_a);
	if (i == 2)
		ft_swap(*stack_b);
	if (i == 3)
		ft_swap_both(*stack_a, *stack_b);
	if (i == 4)
		ft_push(stack_b, stack_a);
	if (i == 5)
		ft_push(stack_a, stack_b);
	if (i == 6)
		ft_rotate(*stack_a);
	if (i == 7)
		ft_rotate(*stack_b);
	if (i == 8)
		ft_rotate_both(*stack_a, *stack_b);
	if (i == 9)
		ft_revrotate(*stack_a);
	if (i == 10)
		ft_revrotate(*stack_b);
	if (i == 11)
		ft_revrotate_both(*stack_a, *stack_b);
	if (i == 12)
		ft_error_msg();
}
