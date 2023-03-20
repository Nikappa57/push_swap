/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:37:44 by lorenzogaud      ###   ########.fr       */
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

void ft_stack_rmv_elm(t_list **stack, int elm_val)
{
	int		i;
	int		position;
	t_list	*tmp;
	t_list	*prev;

	i = 0;
	position = ft_stack_elm_pos(*stack, elm_val) + 1;
	tmp = *stack;
	prev = *stack;
	while (i < position)
	{
		if (i == 0 && position == 1)
		{
			*stack = (*stack)->next;
			ft_lstdelone(tmp);
		}
		else
		{
			if (i == position - 1 && tmp)
			{
				prev->next = tmp->next;
				ft_lstdelone(tmp);
			}
			else
			{
				prev = tmp;
				if (prev == NULL)
					break ;
				tmp = tmp->next;
			}
		}
		i++;
	}
}
