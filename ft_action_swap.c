/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:36:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/23 23:38:47 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	second = *stack_a;
	first = second->next;
	second->next = first->next;
	first->next = second;
	*stack_a = first;
	ft_print_action("sa");
}

void	ft_sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	second = *stack_b;
	first = second->next;
	second->next = first->next;
	first->next = second;
	*stack_b = first;
	ft_print_action("sb");
}
