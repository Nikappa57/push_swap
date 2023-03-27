/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/27 23:43:33 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (0);
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
		return (NULL);
	i = 0;
	while (stack)
	{
		cpy[i++] = stack->content;
		stack = stack->next;
	}
	return (cpy);
}
