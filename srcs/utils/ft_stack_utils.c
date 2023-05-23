/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/05/23 13:53:42 by lgaudino         ###   ########.fr       */
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

void	ft_stack_rmv_elm(t_list **stack, int elm_val)
{
	int		i;
	int		position;
	t_list	*tmp;
	t_list	*prev;

	i = 0;
	tmp = *stack;
	position = ft_stack_elm_pos(*stack, elm_val) + 1;
	while (i < position)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
}
