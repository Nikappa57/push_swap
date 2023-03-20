/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:13:43 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:38:38 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lis_arr(int *v, int len)
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

int	ft_lis_max(int *lis_arr, int len)
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

void	ft_nolis(t_list *stack_a, int v_len, t_list **nolis)
{
	int	i;
	int	*v;
	int	lis_max;
	int	*lis_arr;

	v = ft_copy_stack(stack_a, v_len);
	lis_arr = ft_lis_arr(v, v_len);
	lis_max = ft_lis_max(lis_arr, v_len);
	while (v_len > 0)
	{
		if (lis_arr[--v_len] == lis_max)
			lis_max--;
		else
			ft_lstadd_front(nolis, ft_lstnew(v[v_len]));
	}
	free(lis_arr);
	free(v);
}
