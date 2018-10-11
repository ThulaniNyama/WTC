/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:43:24 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 13:20:04 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_nums_to_stack_a(int *s_a, int len, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		s_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (s_a[i] == s_a[j])
				ft_exit_error();
			j++;
		}
		i++;
	}
}

int		ft_is_valid(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_validate(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid(argv[i]))
			ft_exit_error();
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				ft_exit_error();
			j++;
		}
		i++;
	}
}

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int		main(int argc, char **argv)
{
	int			*stack_a;
	int			*stack_b;
	t_pslist	*sort;

	sort = NULL;
	stack_a = (int*)malloc(sizeof(*stack_a) * (argc - 1));
	stack_b = (int*)malloc(sizeof(*stack_b) * (argc - 1));
	if (argc < 2)
		ft_exit_error();
	else
	{
		ft_validate(argc, argv);
		ft_add_nums_to_stack_a(stack_a, (argc - 1), argv);
		ft_push_swap(stack_a, argc - 1, stack_b, &sort);
		ft_print_list(sort);
	}
	return (0);
}
