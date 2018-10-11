/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:46:56 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/04 13:09:09 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

typedef struct	s_checker
{
	long			*num;
	int				end;
}				t_checker;

typedef	struct	s_savespace
{
	t_checker	array;
	int			i;
	int			j;
	int			k;
}				t_savespace;

typedef	struct	s_save
{
	t_checker	a;
	t_checker	b;
	char		*str;
	int			i;
	int			ret;
}				t_save;

void			ft_swap(t_checker s);
void			ft_swap_both(t_checker sa, t_checker sb);
void			ft_rotate(t_checker s);
void			ft_rotate_both(t_checker s, t_checker sb);
void			ft_revrotate(t_checker s);
void			ft_revrotate_both(t_checker s, t_checker sb);
void			ft_push(t_checker *sa, t_checker *sb);
int				get_op(char *op);
void			ft_error_msg(void);
void			do_op(int i, t_checker *stack_a, t_checker *stack_b);
int				ft_check_order(t_checker stack_a, t_checker stack_b);
void			print_stack(t_checker a, t_checker b, int i);
int				num_val(char **arg, int count);
int				dup_check(long *num, int end);
t_checker		array_maker(char **av, int ac);
int				overflow_check(long *numbers, int k);

#endif
