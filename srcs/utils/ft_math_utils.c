/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:55:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/03 13:25:56 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	ft_max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	if (n1 >= n2)
		return (n2);
	return (n1);
}
