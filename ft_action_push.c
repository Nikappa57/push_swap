/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:35:14 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/27 22:22:07 by lorenzogaud      ###   ########.fr       */
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
