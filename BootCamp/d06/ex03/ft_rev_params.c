/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:01:07 by tnyama            #+#    #+#             */
/*   Updated: 2018/04/18 17:57:53 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int c;
	int i;

	i = argc - 1;
	while (i > 0)
	{
		c = 0;
		while (argv[i][c] != '\0')
		{
			ft_putchar(argv[i][c]);
			c++;
		}
		ft_putchar('\n');
		i--;
	}
	return (0);
}
