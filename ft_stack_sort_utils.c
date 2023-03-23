/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 22:16:08 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_move_elm_front_len(int stack_len, int elm_pos)
{
	if (elm_pos < 0)
		return (0);
	if (elm_pos <= (int)(stack_len / 2))
		return (elm_pos);
	else
		return (elm_pos - stack_len);
}

int	ft_stack_find_min_pos(t_list *stack)
{
	int	i;
	int	min;
	int	min_pos;

	if (!stack)
		return (0);
	min_pos = 0;
	i = 0;
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

int	ft_stack_elm_ismax(t_list *stack, int elm_val)
{
	int	result;

	result = 1;
	while (stack != NULL)
	{
		if (stack->content > elm_val)
			result = 0;
		stack = stack->next;
	}
	return (result);
}

int	ft_stack_elm_ismin(t_list *stack, int elm_val)
{
	int	result;

	result = 1;
	while (stack != NULL)
	{
		if (stack->content < elm_val)
			result = 0;
		stack = stack->next;
	}
	return (result);
}
