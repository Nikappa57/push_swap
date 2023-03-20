/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:04:52 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:09:10 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_n(t_list **stack_a, int ra_n)
{
	int	stack_a_len;

	if (!ra_n)
		return ;
	stack_a_len = ft_lstsize(*stack_a);
	if ((ra_n > 0) && (ra_n > stack_a_len / 2))
		ra_n -= stack_a_len;
	else if ((ra_n < 0) && (ft_abs(ra_n) > stack_a_len / 2))
		ra_n += stack_a_len;
	if (ra_n > 0)
	{
		while (ra_n-- > 0)
			ft_ra(stack_a);
	}
	else
		while (ra_n++)
			ft_rra(stack_a);
}

void	ft_rb_n(t_list **stack_b, int rb_n)
{
	int	stack_b_len;

	if (!rb_n)
		return ;
	stack_b_len = ft_lstsize(*stack_b);
	if ((rb_n > 0) && (rb_n > stack_b_len / 2))
		rb_n -= stack_b_len;
	else if ((rb_n < 0) && (ft_abs(rb_n) > stack_b_len / 2))
		rb_n += stack_b_len;
	if (rb_n > 0)
	{
		while (rb_n-- > 0)
			ft_rb(stack_b);
	}
	else
		while (rb_n++)
			ft_rrb(stack_b);
}

static void	ft_r_find_combo(
	t_list *stack_a, t_list *stack_b, int *ra_n, int *rb_n)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	stack_a_len = ft_lstsize(stack_a);
	if (*ra_n < 0 && *rb_n > 0)
	{	
		if (ft_abs(ft_min(*rb_n - stack_b_len, *ra_n)) < ft_abs(*ra_n) + *rb_n)
			*rb_n -= stack_b_len;
		else if (ft_max(*ra_n + stack_a_len, *rb_n) < ft_abs(*ra_n) + *rb_n)
			*ra_n += stack_a_len;
	}
	else if (*ra_n > 0 && *rb_n < 0)
	{
		if (ft_abs(ft_min(*ra_n - stack_a_len, *rb_n)) < ft_abs(*rb_n) + *ra_n)
			*ra_n -= stack_a_len;
		else if (ft_max(*rb_n + stack_b_len, *ra_n) < ft_abs(*ra_n) + *rb_n)
			*rb_n += stack_b_len;
	}
}

void	ft_r_best_combo(t_list **stack_a, t_list **stack_b, int ra_n, int rb_n)
{
	ft_r_find_combo(*stack_a, *stack_b, &ra_n, &rb_n);
	while (ra_n > 0 && rb_n > 0)
	{
		ft_rr(stack_a, stack_b);
		ra_n--;
		rb_n--;
	}
	while (ra_n < 0 && rb_n < 0)
	{
		ft_rrr(stack_a, stack_b);
		ra_n++;
		rb_n++;
	}
	ft_ra_n(stack_a, ra_n);
	ft_rb_n(stack_b, rb_n);
}
