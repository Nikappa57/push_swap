/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:33:21 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/28 02:40:41 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_len(int len)
{
	if (len <= 10)
		return (1);
	if (len <= 100)
		return (2);
	if (len <= 500)
		return (7);
	return (5);
}

int	ft_is_in_chunk(int all_nbr_len, int chunk, int val)
{
	int	min;
	int	max;
	int	chunk_len;
	int	nbr_per_chunk;

	chunk_len = ft_chunk_len(all_nbr_len);
	nbr_per_chunk = all_nbr_len / chunk_len;
	min = nbr_per_chunk * chunk;
	max = min - 1 + nbr_per_chunk;
	if (val <= max && val >= min)
		return (1);
	if (val >= max && chunk == chunk_len - 1)
		return (1);
	return (0);
}

int	ft_get_chunk(int val, int all_nbr_len)
{
	int	chunk_len;
	int	chunk;

	chunk = 0;
	chunk_len = ft_chunk_len(all_nbr_len);
	while (!ft_is_in_chunk(all_nbr_len, chunk, val))
		chunk++;
	return (chunk);
}

int	ft_is_in_same_chunk(int val_1, int val_2, int all_nbr_len)
{
	return (ft_get_chunk(val_1, all_nbr_len)
		== ft_get_chunk(val_2, all_nbr_len));
}

int	ft_is_min_chunk(t_list *stack_a, t_list *stack_b, int a_val, int all_nbr_len)
{
	int		min;
	int		chunk;
	int		eml_chunk;
	int		stack_a_len;
	t_list	*last_b;

	min = ft_chunk_len(all_nbr_len) - 1;
	stack_a_len = ft_lstlast(stack_a);
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
	eml_chunk = ft_get_chunk(a_val, all_nbr_len);
	last_b = ft_lstlast(stack_b);
	if (stack_a_len < (int)(all_nbr_len / ft_chunk_len(all_nbr_len)))
	{
		if (stack_b && !ft_is_in_same_chunk(
				stack_b->content, a_val, all_nbr_len))
			return (1);
		return (2);
	}
	if (eml_chunk <= min + 1)
	{
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

int	ft_is_max_chunk(t_list *stack_b, int b_val, int all_nbr_len)
{
	int		max;
	int		chunk;
	int		eml_chunk;

	max = 0;
	while (stack_b)
	{
		chunk = ft_get_chunk(stack_b->content, all_nbr_len);
		if (chunk == ft_chunk_len(all_nbr_len) - 1)
		{
			max = ft_chunk_len(all_nbr_len) - 1;
			break ;
		}
		if (chunk > max)
			max = chunk;
		stack_b = stack_b->next;
	}
	eml_chunk = ft_get_chunk(b_val, all_nbr_len);
	if (eml_chunk >= max)
		return (1);
	return (0);
}
// TODO: si può ottimizzare cercando direttamente il chunk dell'elm
// TODO: ultimo chunk da dividere