/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:35:14 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/25 22:22:16 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;
	t_list	*first_a;

	first_b = *stack_b;
	first_a = first_b->next;
	first_b->next = *stack_a;
	*stack_a = first_a;
	*stack_b = first_b;
	ft_print_action("pa");
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;
	t_list	*first_a;

	first_b = *stack_a;
	first_a = first_b->next;
	first_b->next = *stack_b;
	*stack_a = first_a;
	*stack_b = first_b;
	ft_print_action("pb");
}

void	ft_push_to_b(
	t_list **stack_a, t_list **stack_b, int stack_a_len, int content)
{
	int		elm_pos;
	int		i;

	i = 0;
	elm_pos = ft_stack_elm_pos(*stack_a, content);
	if (elm_pos <= (int)(stack_a_len / 2))
	{
		while (i++ < elm_pos - 1)
			ft_ra(stack_a);
		if (elm_pos)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
		i = 0;
		while (i++ < elm_pos - 1)
			ft_rra(stack_a);
	}
	else
	{
		while (i++ < stack_a_len - elm_pos)
			ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		i = 0;
		while (i++ < stack_a_len - elm_pos - 1)
			ft_ra(stack_a);
	}
}
