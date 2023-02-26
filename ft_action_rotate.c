/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:36:30 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/24 11:48:28 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*front;
	t_list	*back;

	back = *stack_a;
	front = back->next;
	ft_lstlast(*stack_a)->next = back;
	back->next = NULL;
	*stack_a = front;
	ft_print_action("ra");
}

void	ft_rb(t_list **stack_b)
{
	t_list	*front;
	t_list	*back;

	back = *stack_b;
	front = back->next;
	ft_lstlast(*stack_b)->next = back;
	back->next = NULL;
	*stack_b = front;
	ft_print_action("rb");
}

void	ft_rra(t_list **stack_a)
{
	t_list	*front;
	t_list	*back;

	front = ft_lstlast(*stack_a);
	front->next = *stack_a;
	*stack_a = front;
	back = *stack_a;
	while (back->next != front && back->next != NULL)
		back = back->next;
	back->next = NULL;
	ft_print_action("rra");
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*front;
	t_list	*back;

	front = ft_lstlast(*stack_b);
	front->next = *stack_b;
	*stack_b = front;
	back = *stack_b;
	while (back->next != front && back->next != NULL)
		back = back->next;
	back->next = NULL;
	ft_print_action("rra");
}
