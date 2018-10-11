/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:43:26 by mgould            #+#    #+#             */
/*   Updated: 2017/03/22 22:02:33 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>

int		validnumbers(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (ps_big_atoi(av[i]) > INT_MAX || ps_big_atoi(av[i]) < INT_MIN)
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				;
			else if (!ft_isdigit(av[i][j]))
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	varparse(t_stack **stack, char *avin)
{
	int j;
	char **tmp;

	j = 0;
	tmp = ft_strsplit(avin, ' ');
	while (tmp[j])
	{
		(*stack)->v = (int)ps_big_atoi(tmp[j]);
		if (!tmp[j + 1])
			break;
		(*stack)->nx = stackinit();
		((*stack)->nx)->pv = (*stack);
		(*stack) = (*stack)->nx;
		j++;
	}
 	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

t_stack	*makestack(char **av)
{
	int		i;
	t_stack *stack;
	t_stack *begin;

	i = 1;
	stack = stackinit();
	begin = stack;
	while (av[i])
	{
		varparse(&stack, av[i]);
		if (!av[i + 1])
			return (begin);
		stack->nx = stackinit();
		(stack->nx)->pv = stack;
		stack = stack->nx;
		i++;
	}
	return (begin);
}

static int	hasdupes(t_stack *stacka)
{
	int num;
	int flag;
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	while (stacka)
	{
		num = stacka->v;
		flag = 0;
		tmpb = tmpa;
		while (tmpb)
		{
			if (tmpb->v == num)
				flag++;
			if (flag > 1)
				return (1);
			tmpb = tmpb->nx;
		}
		stacka = stacka->nx;
	}
	return (0);
}

t_stack	*valinput(int ac, char **av, t_stack *stacka)
{
	int	len;
	char **tmp;

	tmp = av;
	len = 0;
	while (av[len])
		len++;
	if (ac < 2)
		return (NULL);
	if (!(ft_strcmp("-v", tmp[1])))
		tmp++;
	if (!validnumbers(tmp))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stacka = makestack(tmp);
	if (hasdupes(stacka))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stacka);
}
