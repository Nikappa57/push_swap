/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:36:07 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 11:58:10 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	ft_s_stack(stack_a);
	ft_print_action("sa");
}

void	ft_sb(t_list **stack_b)
{
	ft_s_stack(stack_b);
	ft_print_action("sb");
}
