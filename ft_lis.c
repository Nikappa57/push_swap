/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:13:43 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/26 02:38:03 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_lis_arr(int *v, int len)
{
	int	i;
	int	j;
	int	*lis_arr;

	lis_arr = (int *) malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
		lis_arr[i++] = 1;
	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (v[i] > v[j] && lis_arr[i] < lis_arr[j] + 1)
				lis_arr[i] = lis_arr[j] + 1;
			j++;
		}
		i++;
	}
	return (lis_arr);
}

static int	ft_lis_max(int *lis_arr, int len)
{
	int	i;
	int	max;

	i = 0;
	max = 1;
	while (i < len)
	{
		if (lis_arr[i] > max)
			max = lis_arr[i];
		i++;
	}
	return (max);
}

static int	*ft_lis_val_arr(int *v, int v_len, int *lis_arr, int lis_max)
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

static int	*ft_nolis_val_arr(int *v, int v_len, int *lis_arr, int lis_max)
{
	int	i;
	int	*lis_noval_arr;

	i = v_len - lis_max;
	lis_noval_arr = (int *) malloc(sizeof(int) * i);
	if (!lis_noval_arr)
		ft_print_error();
	while (i >= 0)
	{
		v_len--;
		if (lis_arr[v_len] == lis_max)
			lis_max--;
		else
			lis_noval_arr[--i] = v[v_len];
	}
	return (lis_noval_arr);
}

void	ft_move_nolis_to_b(t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int	i;
	int	*v;
	int	lis_len;
	int	*lis_arr;
	int	*nolis_val_arr;

	v = ft_copy_stack(*stack_a, stack_a_len);
	ft_print_arr(v, stack_a_len);
	lis_arr = ft_lis_arr(v, stack_a_len);
	ft_print_arr(lis_arr, stack_a_len);
	lis_len = ft_lis_max(lis_arr, stack_a_len);
	nolis_val_arr = ft_nolis_val_arr(v, stack_a_len, lis_arr, lis_len);
	ft_print_arr(nolis_val_arr, stack_a_len - lis_len);
	i = 0;
	while (i < stack_a_len - lis_len)
		ft_push_to_b(stack_a, stack_b, stack_a_len, nolis_val_arr[i++]);
	free(v);
	free(lis_arr);
	free(nolis_val_arr);
}
// TODO:
// ottimizzare il push su b 
// vedere se si può ruotare entrambi insieme, per esempio se serve ruotare a e ruotare b mi aiuta, fallo tanto sempre una mossa è
// controllare se mentre si carica b si può fare qualche ottimizzazione, come scambiare due numeri