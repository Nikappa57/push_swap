/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:11:22 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/28 02:45:05 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_elm_to_a(
	t_list **stack_a, t_list **stack_b, int b_elm_pos, int stack_a_len)
{
	int	rb_n;
	int	ra_n;
	int	a_elm_pos;
	int	stack_b_len;

	stack_b_len = ft_lstsize(*stack_b);
	a_elm_pos = ft_find_a_elm(*stack_a, *stack_b, b_elm_pos);
	if (a_elm_pos == -1)
		return ;
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	ra_n = ft_move_elm_front_len(stack_a_len, a_elm_pos);
	if (ra_n == 0
		&& ft_stack_elm_ismax(*stack_a, ft_stack_elm_val(*stack_b, b_elm_pos)))
	{
		if (ft_stack_elm_ismax(*stack_a, ft_stack_elm_val(*stack_a, 0)))
			ra_n = 1;
		else
			ra_n = ft_stack_find_min_pos(*stack_a);
	}
	ft_r_best_combo(stack_a, stack_b, ra_n, rb_n);
	ft_pa(stack_a, stack_b);
}

static int	ft_b_elm_pos(t_list *stack_a, t_list *stack_b,
	int stack_a_len, int stack_b_len)
{
	int	ra_n;
	int	b_elm_pos;
	int	tmp_move;
	int	min_move;
	int	min_elm_pos;

	b_elm_pos = 0;
	min_move = stack_a_len + stack_b_len;
	while (b_elm_pos < stack_b_len)
	{
		if (ft_is_max_chunk(stack_b, ft_stack_elm_val(
					stack_b, b_elm_pos), stack_a_len + stack_b_len))
		{
			ra_n = ft_b_elm_pos_ra(stack_a, stack_b, stack_a_len, b_elm_pos);
			tmp_move = ft_push_elm_to_a_len(ra_n,
					ft_move_elm_front_len(stack_b_len, b_elm_pos));
			if (tmp_move < min_move && tmp_move != -1)
			{
				min_move = tmp_move;
				min_elm_pos = b_elm_pos;
			}
		}
		b_elm_pos++;
	}
	return (min_elm_pos);
}

void	ft_push_to_a(
	t_list **stack_a, t_list **stack_b, int stack_a_len, int stack_b_len)
{
	int	b_elm_pos;

	while (stack_b_len)
	{
		b_elm_pos = ft_b_elm_pos(
				*stack_a, *stack_b, stack_a_len, stack_b_len);
		ft_push_elm_to_a(stack_a, stack_b, b_elm_pos, stack_a_len++);
		stack_b_len--;
	}
	ft_ra_n(stack_a, ft_stack_find_min_pos(*stack_a));
}
