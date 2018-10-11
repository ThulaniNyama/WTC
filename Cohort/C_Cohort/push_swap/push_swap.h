/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnyama <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:30:12 by tnyama            #+#    #+#             */
/*   Updated: 2018/09/02 20:43:51 by tnyama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int					g_aitems;
int					g_bitems;
int					g_count;
typedef	struct		s_pslist
{
	int				sort;
	struct s_pslist	*next;
}					t_pslist;

void				ft_exit_error(void);
void				ft_validate(int argc, char **argv);
void				ft_print_result(int *l_a, int items);
void				ft_print_list(t_pslist *list);
void				ft_add_nums_to_stack_a(int *s_a, int len, char **argv);
void				ft_push_swap(int *s_a, int len, int *s_b, t_pslist **sort);
void				ft_swap(int *l_a, t_pslist **ops);
void				ft_swapb(int *l_a, t_pslist **ops);
void				ft_push(int *l_a, int *l_b, t_pslist **ops);
void				ft_pushb(int *l_a, int *l_b, t_pslist **ops);
void				ft_rotate_first_to_end(int *l_a, t_pslist **ops);
void				ft_rotate_first_to_endb(int *l_a, t_pslist **ops);
void				ft_rotate_last_to_start(int *l_a, t_pslist **ops);
void				ft_rotate_last_to_startb(int *l_a, t_pslist **ops);
int					*ft_bubble_sort(int *l_a);
int					ft_l_a_is_complete_and_sorted(int *l_a, int items);
int					ft_l_a_is_sorted(int *l_a);
int					ft_find_shortest_route_of_smallest_number(int *l_a);
int					ft_find_smallest_number(int *l_a);
int					ft_find_its_position(int *l_a, int small);
void				ft_execute_route_1(int *l_a, t_pslist **ops, int *l_b);
void				ft_execute_route_2(int *l_a, t_pslist **ops, int *l_b);
int					ft_smallest_is_first(int *tab);
void				ft_add_to_list(t_pslist **start, int s);
int					ft_nbr_of_sorted_is_bigger_than_unsorted(int *l_a);
void				ft_solve_case_special(int *l_a, t_pslist **ops, int *l_b,
		int items);
void				ft_solve_decreasing_list(int *l_a, t_pslist **ops,
		int *l_b);
int					ft_l_a_is_sorted_decreasing(int *l_a);
int					ft_nbr_of_sorted_is_bigger_than_unsorted(int *l_a);
int					ft_biggest_is_first(int *l_a);
#endif
