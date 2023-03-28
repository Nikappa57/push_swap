/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:33:21 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/29 00:28:58 by lorenzogaud      ###   ########.fr       */
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
	int	chunk_tmp;

	chunk_len = ft_chunk_len(all_nbr_len);
	if (chunk_len == 1)
		return (1);
	if (chunk + 1 > chunk_len + 4)
		return (ft_print_error(NULL, NULL));
	if (chunk + 1 > chunk_len)
		chunk_tmp = chunk_len - 1;
	else
		chunk_tmp = chunk;
	nbr_per_chunk = all_nbr_len / (chunk_len + 2);
	min = nbr_per_chunk * chunk_tmp;
	max = min - 1 + nbr_per_chunk;
	if (val <= max && val >= min)
		return (1);
	if (chunk + 1 <= chunk_len)
		return (0);
	min = max + (nbr_per_chunk / 2) * (chunk - chunk_len);
	max = min - 1 + nbr_per_chunk / 2;
	if (val <= max && val >= min)
		return (1);
	if (val >= max && chunk + 1 == chunk_len + 4)
		return (1);
	return (0);
}

int	ft_get_chunk(int val, int all_nbr_len)
{
	int	chunk;

	chunk = 0;
	while (!ft_is_in_chunk(all_nbr_len, chunk, val))
		chunk++;
	return (chunk);
}

int	ft_is_in_same_chunk(int val_1, int val_2, int all_nbr_len)
{
	return (ft_get_chunk(val_1, all_nbr_len)
		== ft_get_chunk(val_2, all_nbr_len));
}
