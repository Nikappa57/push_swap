/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:36:30 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 11:56:13 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p_stack(t_list **from, t_list **dst)
{
	t_list	*first_dst;
	t_list	*first_from;

	first_dst = *from;
	first_from = first_dst->next;
	first_dst->next = *dst;
	*from = first_from;
	*dst = first_dst;
}

void	ft_s_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	second = *stack;
	first = second->next;
	second->next = first->next;
	first->next = second;
	*stack = first;
}

void	ft_r_stack(t_list **stack)
{
	t_list	*front;
	t_list	*back;

	back = *stack;
	front = back->next;
	ft_lstlast(*stack)->next = back;
	back->next = NULL;
	*stack = front;
}

void	ft_rr_stack(t_list **stack)
{
	t_list	*front;
	t_list	*back;

	front = ft_lstlast(*stack);
	front->next = *stack;
	*stack = front;
	back = *stack;
	while (back->next != front && back->next != NULL)
		back = back->next;
	back->next = NULL;
}
