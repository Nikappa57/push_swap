/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:03:19 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:44:10 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		ft_print_error(void);
void	ft_print_action(char *last_action);

void	ft_short_sort(t_list **stack_a, t_list **stack_b, int stack_a_len);

void	ft_simplify_stack(t_list *stack_a, int stack_a_len);

// TEST
int		ft_check_ord_after_ra(t_list *stack_a, int ra_n);
int		ft_stack_elm_pos(t_list *stack, int content);
int		*ft_copy_stack(t_list *stack, int len);
int		ft_stack_elm_val(t_list *stack, int pos);
int		ft_stack_elm_ismax(t_list *stack, int elm_val);
int		ft_stack_elm_ismin(t_list *stack, int elm_val);
int		ft_stack_find_min_pos(t_list *stack);
int		ft_is_sort(t_list *stack_a);
void 	ft_stack_rmv_elm(t_list **stack, int elm_val);

int		ft_abs(int n);
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);

int		ft_parse_args(int argc, char **argv, t_list **stack_a);

int		*ft_lis_arr(int *v, int len);
int		ft_lis_max(int *lis_arr, int len);
void	ft_nolis(t_list *stack_a, int v_len, t_list **nolis);

void	ft_push_to_a(t_list **stack_a, t_list **stack_b,
			int stack_a_len, int stack_b_len);
void	ft_push_to_b(
			t_list **stack_a, t_list **stack_b, int stack_a_len);

void	ft_p_stack(t_list **from, t_list **dst);
void	ft_s_stack(t_list **stack);
void	ft_r_stack(t_list **stack);
void	ft_rr_stack(t_list **stack);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);

void	ft_ra_n(t_list **stack_a, int ra_n);
void	ft_r_best_combo(t_list **stack_a, t_list **stack_b, int ra_n, int rb_n);
int		ft_move_elm_front_len(int stack_len, int elm_pos);
int		ft_chunk_len(int len);

int		ft_push_elm_to_a_len(int ra_n, int rb_n);
int		ft_b_elm_pos_ra(t_list *stack_a, t_list *stack_b,
			int stack_a_len, int b_elm_pos);
int		ft_find_a_elm(t_list *stack_a, t_list *stack_b, int b_elm_pos);

int		ft_chunk_len(int len);
int		ft_is_in_chunk(int all_nbr_len, int chunk, int val);
int		ft_get_chunk(int val, int all_nbr_len);
int		ft_is_in_same_chunk(int all_nbr_len, int val_1, int val_2);
#endif