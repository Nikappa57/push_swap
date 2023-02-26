/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:15:36 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/26 01:44:21 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		ft_print_error(void);
void	ft_print_stack(t_list *stack_a, t_list *stack_b);
void	ft_print_action(char *last_action);
void	ft_print_arr(int *arr, int len);

int		ft_stack_elm_pos(t_list *stack, int content);
int		*ft_copy_stack(t_list *stack, int len);

int		ft_parse_args(int argc, char **argv, t_list **stack_a);
int		ft_stack_elm_pos(t_list *stack, int content);

void	ft_move_nolis_to_b(t_list **stack_a, t_list **stack_b, int stack_a_len);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_push_to_b(
			t_list **stack_a, t_list **stack_b, int stack_a_len, int content);
#endif