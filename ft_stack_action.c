/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:36:30 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/19 01:31:23 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_p_stack(t_list **from, t_list **dst)
{
	t_list	*first_dst;
	t_list	*first_from;

	if (!*from)
		return ;
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

	if (!*stack)
		return ;
	second = *stack;
	first = second->next;
	if (!first)
		return ;
	second->next = first->next;
	first->next = second;
	*stack = first;
}

void	ft_r_stack(t_list **stack)
{
	t_list	*front;
	t_list	*back;

	if (!*stack)
		return ;
	back = *stack;
	front = back->next;
	if (!front)
		return ;
	ft_lstlast(*stack)->next = back;
	back->next = NULL;
	*stack = front;
}

void	ft_rr_stack(t_list **stack)
{
	t_list	*front;
	t_list	*back;

	if (!*stack)
		return ;
	front = ft_lstlast(*stack);
	front->next = *stack;
	*stack = front;
	back = *stack;
	while (back->next != front && back->next != NULL)
		back = back->next;
	back->next = NULL;
}
