/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:13:43 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/27 22:22:44 by lorenzogaud      ###   ########.fr       */
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
// TODO:
// vedere se si può ruotare entrambi insieme, per esempio se serve ruotare a e ruotare b mi aiuta, fallo tanto sempre una mossa è
// controllare se mentre si carica b si può fare qualche ottimizzazione, come scambiare due numeri