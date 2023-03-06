/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:19:56 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/06 14:39:22 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	int	ra_n;
	int	ra_len;
	int	nolis_len;
	int	*nolis_arr;

	v = ft_copy_stack(*stack_a, stack_a_len);
	ra_len = 0;
	nolis_arr = ft_nolis_val_arr(v, stack_a_len, &nolis_len);
	if (!nolis_len)
		return ;
	ra_n = ft_find_best_push_b(
			*stack_a, stack_a_len, &nolis_arr, nolis_len--);
	while (ra_n < stack_a_len && nolis_len >= 0)
	{
		ft_ra_n_pb(stack_a, stack_b, ra_n);
		stack_a_len--;
		ra_len += ra_n;
		if (ra_n < 0)
			ra_len++;
		ra_n = ft_find_best_push_b(
				*stack_a, stack_a_len, &nolis_arr, nolis_len--);
	}
	free(v);
	free(nolis_arr);
}
