/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:11:22 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:38:25 by lorenzogaud      ###   ########.fr       */
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
	int	i;
	int	a_val;
	int	min_move;
	int	min_b_pos;
	int	stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	i = 0;
	min_b_pos = 0;
	min_move = stack_a_len + stack_b_len;
	a_val = ft_stack_elm_val(stack_a, a_elm_pos);
	while (i < stack_b_len)
	{
		if (ft_is_in_same_chunk(stack_a_len + stack_b_len, a_val,
				stack_b->content) && (min_move > ft_push_elm_to_b_len(
					stack_a_len, a_elm_pos, stack_b_len, i)))
		{
			min_move = ft_push_elm_to_b_len(
					stack_a_len, a_elm_pos, stack_b_len, i);
			min_b_pos = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (min_b_pos);
}

static void	ft_push_elm_to_b(
	t_list **stack_a, t_list **stack_b, int min_elm_pos, int stack_a_len)
{
	int	rb_n;
	int	rb_after_pb;
	int	ra_n;
	int	b_elm_pos;
	int	stack_b_len;

	rb_after_pb = 0;
	stack_b_len = ft_lstsize(*stack_b);
	b_elm_pos = ft_find_b_elm_pos(*stack_a, *stack_b, min_elm_pos, stack_a_len);
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	if (rb_n < 0)
		rb_after_pb = 1;
	rb_n += rb_after_pb;
	ra_n = ft_move_elm_front_len(stack_a_len, min_elm_pos);
	ft_r_best_combo(stack_a, stack_b, ra_n, rb_n);
	ft_pb(stack_a, stack_b);
	if (rb_after_pb)
		ft_rb(stack_b);
}

static int	ft_min_elm(t_list *stack_a, t_list *stack_b,
	t_list *nolis_list, int stack_a_len)
{
	int			a_elm_pos;
	int			tmp_move;
	int			min_move;
	int			min_elm;
	int			stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	min_move = stack_a_len + stack_b_len;
	while (nolis_list)
	{
		a_elm_pos = ft_stack_elm_pos(stack_a, nolis_list->content);
		tmp_move = ft_push_elm_to_b_len(stack_a_len, a_elm_pos, stack_b_len,
				ft_find_b_elm_pos(stack_a, stack_b, a_elm_pos, stack_a_len));
		if (tmp_move < min_move && tmp_move != -1)
		{
			min_move = tmp_move;
			min_elm = nolis_list->content;
		}
		nolis_list = nolis_list->next;
	}
	return (min_elm);
}

void	ft_push_to_b(
	t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int		nolis_len;
	int		min_elm;
	int		all_nbr_len;
	int		stack_b_len;
	t_list	*nolis_list;

	stack_b_len = 0;
	all_nbr_len = stack_a_len;
	nolis_list = NULL;
	ft_nolis(*stack_a, stack_a_len, &nolis_list);
	nolis_len = ft_lstsize(nolis_list);
	while (nolis_len > 0)
	{
		min_elm = ft_min_elm(
				*stack_a, *stack_b, nolis_list, stack_a_len);
		ft_stack_rmv_elm(&nolis_list, min_elm);
		ft_push_elm_to_b(stack_a, stack_b, ft_stack_elm_pos(
				*stack_a, min_elm), stack_a_len);
		stack_b_len++;
		stack_a_len--;
		nolis_len--;
	}
	ft_lstclear(&nolis_list);
}
