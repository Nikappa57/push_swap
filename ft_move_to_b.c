/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:19:56 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/10 00:55:24 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

// TODO trovare i migliori dati (ricorda è la lunghezza del non lis)
static int	ft_chunk_len(int len)
{
	if (len <= 10)
		return (2);
	if (len <= 100)
		return (5);
	if (len <= 500)
		return (11);
	return (0);
}

static int	ft_is_in_chunk(int n_per_chunk, int chunk, int val)
{
	int	min;
	int	max;

	min = n_per_chunk * chunk;
	max = min - 1 + n_per_chunk;
	// printf("MIN: %d, MAX: %d, VAL: %d\n", min, max, val);
	if (val <= max && val >= min)
	{
		// printf("SI\n");
		return (1);
	}
	return (0);
}

int	*ft_arr_filter_chunk(int *arr, int arr_len, int all_nbr_len, int *result_len)
{
	int			i;
	int			j;
	int			nbr_per_chunk;
	int			*result;
	static int	chunk;

	if (all_nbr_len % 2)
		all_nbr_len++;
	// printf("ALL NBR LEN: %d\n", all_nbr_len);
	nbr_per_chunk = all_nbr_len / ft_chunk_len(all_nbr_len);
	// printf("NBR PER CHUNK: %d\n", nbr_per_chunk);
	i = 0;
	*result_len = 0;
	while (i < arr_len)
		if (ft_is_in_chunk(nbr_per_chunk, chunk, arr[i++]))
			(*result_len)++;
	// printf("RESULT LEN: %d\n", *result_len);
	if (!result_len)
		return (NULL);
	result = (int *) malloc(sizeof(int) * (*result_len));
	if (!result)
		return (NULL);
	j = 0;
	i = 0;
	while (i < arr_len)
	{
		if (ft_is_in_chunk(nbr_per_chunk, chunk, arr[i]))
			result[j++] = arr[i];
		i++;
	}
	chunk++;
	return (result);
}

int	*ft_remove_elms_arr(int *arr, int *arr_len, int *rmv_arr, int rmv_len)
{
	int	i;
	int	j;
	int	k;
	int	*result;
	int	to_rmv;

	result = (int *) malloc(sizeof(int) * (*arr_len - rmv_len));
	i = 0;
	k = 0;
	while (i < *arr_len)
	{
		j = 0;
		to_rmv = 0;
		while (j < rmv_len && !to_rmv)
			if (arr[i] == rmv_arr[j++])
				to_rmv = 1;
		if (!to_rmv)
			result[k++] = arr[i];
		i++;
	}
	*arr_len -= rmv_len;
	free(arr);
	return (result);
}

static void	ft_remove_nolis_elm(int **arr, int len, int pos)
{
	int	i;

	if (pos < 0 || pos > len || len <= 0)
		return ;
	i = pos;
	while (i < len - 1)
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
}

// TEST
int	*ft_lis_val_arr(int *v, int v_len, int *lis_arr, int lis_max)
{
	int	*lis_val_arr;

	lis_val_arr = (int *) malloc(sizeof(int) * lis_max);
	if (!lis_val_arr)
		ft_print_error();
	while (lis_max > 0)
	{
		if (lis_arr[v_len] == lis_max)
			lis_val_arr[--lis_max] = v[v_len];
		v_len--;
	}
	return (lis_val_arr);
}

static int	*ft_nolis_val_arr(int *v, int v_len, int *nolis_len)
{
	int	i;
	int	lis_len;
	int	*lis_arr;
	int	*lis_noval_arr;

	lis_arr = ft_lis_arr(v, v_len);
	lis_len = ft_lis_max(lis_arr, v_len);
	*nolis_len = v_len - lis_len;
	lis_noval_arr = (int *) malloc(sizeof(int) * *nolis_len);
	if (!lis_noval_arr)
		ft_print_error();
	i = *nolis_len;
	while (i >= 0)
	{
		if (lis_arr[--v_len] == lis_len)
			lis_len--;
		else
			lis_noval_arr[--i] = v[v_len];
	}
	free(lis_arr);
	return (lis_noval_arr);
}

// static int	ft_find_min_move_elm_chunk(t_list *stack_a, int chunk)
// {
// 	int	move;
// 	int	min_move;

	
// }

// static int	ft_find_best_chunk(t_list *stack_a, t_list *stack_b,
// 	int stack_a_len, int stack_b_len)
// {
// 	static int	all_nbr_len;
// 	int			chunk;
// 	int			chunk_len;
// 	int			tmp_move;
// 	int			min_move;

// 	if (!all_nbr_len)
// 		all_nbr_len = stack_a_len;
// 	chunk_len = ft_chunk_len(all_nbr_len);
// 	chunk = 0;
// 	while (chunk < chunk_len)
// 	{
// 		chunk++;
// 	}
// }

// static int	*ft_nolis_chunk(int all_nbr_len, int *nolis_arr, int nolis_len, int *nolis_chunk_len)
// {
// 	int			i;
// 	int			j;
// 	int			*nolis_chunk;
// 	static int	chunk;

// 	i = 0;
// 	*nolis_chunk_len = 0;
// 	while (i < nolis_len)
// 		if (ft_is_in_chunk(all_nbr_len, chunk, nolis_arr[i++]))
// 			(*nolis_chunk_len)++;
// 	if (!(*nolis_chunk_len))
// 	{
// 		chunk++;
// 		ft_nolis_chunk(all_nbr_len, nolis_arr, nolis_len);
// 	}
// 	nolis_chunk = (int *)malloc(sizeof(int) * *nolis_chunk_len);
// 	j = 0;
// 	while (--i >= 0 && nolis_chunk)
// 	{
// 		if (ft_is_in_chunk(all_nbr_len, chunk, nolis_arr[i]))
// 			nolis_chunk[j++] = nolis_arr[i];
// 	}
// 	return (nolis_chunk);
// }

static int	ft_find_best_push_b(
	t_list *stack_a, int stack_a_len, int **nolis_arr, int nolis_len)
{
	int	i;
	int	move;
	int	elm_pos;
	int	min_move;
	int	min_elm_pos;

	i = 0;
	min_move = stack_a_len;
	min_elm_pos = -1;
	while (i < nolis_len)
	{
		elm_pos = ft_stack_elm_pos(stack_a, (*nolis_arr)[i++]);
		if (elm_pos <= (int)(stack_a_len / 2))
			move = elm_pos;
		else
			move = elm_pos - stack_a_len;
		if (ft_abs(min_move) > ft_abs(move) && elm_pos != -1)
		{
			min_move = move;
			min_elm_pos = i - 1;
		}
	}
	ft_remove_nolis_elm(nolis_arr, nolis_len, min_elm_pos);
	return (min_move);
}

void	ft_move_nolis_to_b(t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int	*v;
	int	nolis_len;
	int	*nolis_arr;
	int	chunk;
	int	all_nbr_len;
	int	*nolis_chunk_arr;
	int	nolis_chunk_len;

	v = ft_copy_stack(*stack_a, stack_a_len);
	nolis_arr = ft_nolis_val_arr(v, stack_a_len, &nolis_len);
	all_nbr_len = stack_a_len;
	// printf("NO LIS: \n");
	// ft_print_arr(nolis_arr, nolis_len);
	while (chunk <= ft_chunk_len(all_nbr_len))
	{
		// printf("CHUNK: %d\n", chunk);
		nolis_chunk_arr = ft_arr_filter_chunk(
				nolis_arr, nolis_len, all_nbr_len, &nolis_chunk_len);
		// printf("NO LIS CHUNK %d len: %d\n", chunk, nolis_chunk_len);
		// ft_print_arr(nolis_chunk_arr, nolis_chunk_len);
		nolis_arr = ft_remove_elms_arr(
				nolis_arr, &nolis_len, nolis_chunk_arr, nolis_chunk_len);
		while (nolis_chunk_len > 0)
			ft_ra_n_pb(stack_a, stack_b, ft_find_best_push_b(*stack_a,
					stack_a_len--, &nolis_chunk_arr, nolis_chunk_len--));
		chunk++;
		free(nolis_chunk_arr);
	}
	free(nolis_arr);
	free(v);
}
