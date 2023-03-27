/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:11:22 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/28 01:52:38 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push_elm_to_b_len(int stack_a_len, int a_elm_pos,
	int stack_b_len, int b_elm_pos)
{
	int	ra_n;
	int	rb_n;
	int	rb_after_pb;

	ra_n = ft_move_elm_front_len(stack_a_len, a_elm_pos);
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	rb_after_pb = 0;
	if (rb_n < 0)
		rb_after_pb = 1;
	rb_n += rb_after_pb;
	if (ra_n > 0 && rb_n > 0)
		return (ft_max(ra_n, rb_n) + rb_after_pb);
	else if (ra_n < 0 && rb_n < 0)
		return (ft_abs(ft_min(ra_n, rb_n)) + rb_after_pb);
	return (ft_abs(ra_n) + ft_abs(rb_n) + rb_after_pb);
}

static int	ft_find_b_elm_pos(
	t_list *stack_a, t_list *stack_b, int a_elm_pos, int stack_a_len)
{
	int	a_val;
	int	stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	a_val = ft_stack_elm_val(stack_a, a_elm_pos);
	if (ft_is_min_chunk(
			stack_a, stack_b, a_val, stack_a_len + stack_b_len) == 2)
		return (stack_b_len - 1);
	return (0);
}

static void	ft_push_elm_to_b(
	t_list **stack_a, t_list **stack_b, int a_elm_pos, int stack_a_len)
{
	int	rb_n;
	int	rb_after_pb;
	int	ra_n;
	int	b_elm_pos;
	int	stack_b_len;

	rb_after_pb = 0;
	stack_b_len = ft_lstsize(*stack_b);
	b_elm_pos = ft_find_b_elm_pos(*stack_a, *stack_b, a_elm_pos, stack_a_len);
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	if (rb_n < 0)
		rb_after_pb = 1;
	rb_n += rb_after_pb;
	ra_n = ft_move_elm_front_len(stack_a_len, a_elm_pos);
	ft_r_best_combo(stack_a, stack_b, ra_n, rb_n);
	ft_pb(stack_a, stack_b);
	if (rb_after_pb)
		ft_rb(stack_b);
}

static int	ft_a_elm_pos(t_list *stack_a, t_list *stack_b,
	int stack_a_len, int stack_b_len)
{
	int		a_elm_pos;
	int		tmp_move;
	int		min_move;
	int		min_elm_pos;
	t_list	*a_elm;

	a_elm_pos = 0;
	min_move = stack_a_len + stack_b_len;
	a_elm = stack_a;
	while (a_elm)
	{
		if (ft_is_min_chunk(
				stack_a, stack_b, a_elm->content, stack_a_len + stack_b_len))
		{
			tmp_move = ft_push_elm_to_b_len(
					stack_a_len, a_elm_pos, stack_b_len, ft_find_b_elm_pos(
						stack_a, stack_b, a_elm_pos, stack_a_len));
			if (tmp_move <= min_move && tmp_move != -1)
			{
				min_move = tmp_move;
				min_elm_pos = a_elm_pos;
			}
		}
		a_elm = a_elm->next;
		a_elm_pos++;
	}
	return (min_elm_pos);
}

void	ft_push_to_b(
	t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int		a_eml_pos;
	int		all_nbr_len;
	int		stack_b_len;

	stack_b_len = 0;
	all_nbr_len = stack_a_len;
	while (!ft_is_sort(*stack_a))
	{
		a_eml_pos = ft_a_elm_pos(
				*stack_a, *stack_b, stack_a_len, stack_b_len);
		ft_push_elm_to_b(stack_a, stack_b, a_eml_pos, stack_a_len);
		stack_b_len++;
		stack_a_len--;
	}
}
