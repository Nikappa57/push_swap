/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:22:47 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 12:24:45 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3(t_list **stack_a)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = ft_stack_elm_val(*stack_a, 0);
	e2 = ft_stack_elm_val(*stack_a, 1);
	e3 = ft_stack_elm_val(*stack_a, 2);
	if ((e1 > e2) && (e2 < e3) && (e3 > e1))
		ft_sa(stack_a);
	else if ((e1 > e2) && (e2 > e3) && (e3 < e1))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((e1 > e2) && (e2 < e3) && (e3 < e1))
		ft_ra(stack_a);
	else if ((e1 < e2) && (e2 > e3) && (e3 > e1))
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((e1 < e2) && (e2 > e3) && (e3 < e1))
		ft_rra(stack_a);
}

void	ft_short_sort(t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int	stack_b_len;

	if (stack_a_len == 2 && ((*stack_a)->content > (*stack_a)->next->content))
		ft_sa(stack_a);
	else if (stack_a_len == 3)
		ft_sort_3(stack_a);
	else if (stack_a_len > 3 && !ft_is_sort(*stack_a))
	{
		stack_b_len = stack_a_len - 3;
		while (stack_a_len-- > 3)
			ft_pb(stack_a, stack_b);
		ft_sort_3(stack_a);
		ft_push_to_a(stack_a, stack_b, stack_a_len + 1, stack_b_len);
		ft_lstclear(stack_b);
	}
	ft_lstclear(stack_a);
}
