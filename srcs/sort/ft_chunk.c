/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:33:21 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:36:15 by lorenzogaud      ###   ########.fr       */
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
		return (5);
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

int	ft_is_in_same_chunk(int all_nbr_len, int val_1, int val_2)
{
	return (ft_get_chunk(val_1, all_nbr_len)
		== ft_get_chunk(val_2, all_nbr_len));
}
