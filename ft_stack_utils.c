/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/06 20:08:39 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_find_min_pos(t_list *stack)
{
	int	i;
	int	min;
	int	min_pos;

	if (!stack)
		return (ft_print_error());
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

int	ft_stack_elm_pos(t_list *stack, int content)
{
	int	pos;

	pos = 0;
	while (stack->content != content)
	{
		if (!(stack->next))
			return (-1);
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	ft_stack_elm_val(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i++ < pos)
	{
		if (!(stack->next))
			return (ft_print_error());
		stack = stack->next;
	}
	return (stack->content);
}

int	*ft_copy_stack(t_list *stack, int len)
{
	int	i;
	int	*cpy;

	cpy = (int *)malloc(sizeof(int) * len);
	if (!cpy)
		ft_print_error();
	i = 0;
	while (stack)
	{
		cpy[i++] = stack->content;
		stack = stack->next;
	}
	return (cpy);
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
