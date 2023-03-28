/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:36:25 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/29 00:20:28 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_min_chunk(t_list *stack_a, int all_nbr_len)
{
	int		min;
	int		chunk;

	min = ft_chunk_len(all_nbr_len) + 4 - 1;
	while (stack_a)
	{
		chunk = ft_get_chunk(stack_a->content, all_nbr_len);
		if (chunk == 0)
		{
			min = 0;
			break ;
		}
		if (chunk < min)
			min = chunk;
		stack_a = stack_a->next;
	}
	return (min);
}

int	ft_is_min_chunk(t_list *stack_a, t_list *stack_b, int a_val, int all_nbr_len)
{
	int		min;
	int		chunk_len;
	int		eml_chunk;
	int		stack_a_len;
	t_list	*last_b;

	stack_a_len = ft_lstsize(stack_a);
	eml_chunk = ft_get_chunk(a_val, all_nbr_len);
	chunk_len = ft_chunk_len(all_nbr_len) + 4;
	last_b = ft_lstlast(stack_b);
	min = ft_get_min_chunk(stack_a, all_nbr_len);
	if (eml_chunk <= min + 1)
	{
		if (eml_chunk == 0)
			return (2);
		if (stack_b && ft_is_in_same_chunk(
				stack_b->content, a_val, all_nbr_len))
			return (1);
		if (last_b && ft_is_in_same_chunk(
				last_b->content, a_val, all_nbr_len))
			return (2);
		if (last_b && eml_chunk == ft_get_chunk(
				last_b->content, all_nbr_len) + 2)
			return (2);
		return (1);
	}
	return (0);
}

int	ft_is_max_chunk(t_list *stack_b, int b_pos, int all_nbr_len)
{
	int		chunk;
	int		eml_chunk;
	int		b_val;

	b_val = ft_stack_elm_val(stack_b, b_pos);
	eml_chunk = ft_get_chunk(b_val, all_nbr_len);
	while (stack_b)
	{
		chunk = ft_get_chunk(stack_b->content, all_nbr_len);
		if (eml_chunk < chunk)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}
// TODO: si può ottimizzare cercando direttamente il chunk dell'elm
// TODO: ultimo chunk da dividere