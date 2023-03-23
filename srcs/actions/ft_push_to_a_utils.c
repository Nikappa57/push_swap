/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:31 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 22:55:04 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_elm_to_a_len(int ra_n, int rb_n)
{
	if (ra_n > 0 && rb_n > 0)
		return (ft_max(ra_n, rb_n));
	else if (ra_n < 0 && rb_n < 0)
		return (ft_abs(ft_min(ra_n, rb_n)));
	return (ft_abs(ra_n) + ft_abs(rb_n));
}

int	ft_find_a_elm(
	t_list *stack_a, t_list *stack_b, int b_elm_pos)
{
	int				i;
	int				a_val;
	int				b_val;
	unsigned int	min_diff;
	int				min_a_pos;

	i = 0;
	b_val = ft_stack_elm_val(stack_b, b_elm_pos);
	min_diff = 0;
	min_a_pos = 0;
	while (stack_a)
	{
		a_val = stack_a->content;
		if ((b_val < a_val)
			&& ((min_diff > (unsigned int)(a_val - b_val)) || (!min_diff)))
		{
			min_diff = a_val - b_val;
			min_a_pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (min_a_pos);
}

int	ft_b_elm_pos_ra(t_list *stack_a, t_list *stack_b,
	int stack_a_len, int b_elm_pos)
{
	int	ra_n;

	ra_n = ft_move_elm_front_len(stack_a_len,
			ft_find_a_elm(stack_a, stack_b, b_elm_pos));
	if (ra_n == 0
		&& ft_stack_elm_ismax(
			stack_a, ft_stack_elm_val(stack_b, b_elm_pos)))
	{
		if (ft_stack_elm_ismax(stack_a, ft_stack_elm_val(stack_a, 0)))
			ra_n = 1;
		else
			ra_n = ft_stack_find_min_pos(stack_a);
	}
	return (ra_n);
}
