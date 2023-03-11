/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:15:36 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/10 20:08:01 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int				ft_print_error(void);
void			ft_print_stack(t_list *stack_a, t_list *stack_b);
void			ft_print_action(char *last_action);
void			ft_print_arr(int *arr, int len);

void			ft_short_sort(
					t_list **stack_a, t_list **stack_b, int stack_a_len);

void			ft_simplify_stack(t_list *stack_a, int stack_a_len);

// TEST
int		ft_check_ord_after_ra(t_list *stack_a, int ra_n);
int		ft_stack_elm_pos(t_list *stack, int content);
int		*ft_copy_stack(t_list *stack, int len);
int		ft_stack_elm_val(t_list *stack, int pos);
int		ft_stack_elm_ismax(t_list *stack, int elm_val);
int		ft_stack_elm_ismin(t_list *stack, int elm_val);
int		ft_stack_find_min_pos(t_list *stack);

int		ft_abs(int n);
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);

int		ft_parse_args(int argc, char **argv, t_list **stack_a);

int		*ft_lis_arr(int *v, int len);
int		ft_lis_max(int *lis_arr, int len);
// void	ft_move_nolis_to_b(t_list **stack_a, t_list **stack_b, int stack_a_len);

void	ft_push_to_a(t_list **stack_a, t_list **stack_b,
			int stack_a_len, int stack_b_len);
void	ft_push_to_b(
			t_list **stack_a, t_list **stack_b, int stack_a_len);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);

void	ft_ra_n(t_list **stack_a, int ra_n);
void	ft_ra_n_pb(t_list **stack_a, t_list **stack_b, int ra_n);
void	ft_rb_n_pa(t_list **stack_a, t_list **stack_b, int rb_n);
void	ft_r_best_combo(t_list **stack_a, t_list **stack_b,
			int ra_n, int rb_n);
#endif