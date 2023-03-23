/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:36:30 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 12:00:57 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	ft_r_stack(stack_a);
	ft_print_action("ra");
}

void	ft_rb(t_list **stack_b)
{
	ft_r_stack(stack_b);
	ft_print_action("rb");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_r_stack(stack_a);
	ft_r_stack(stack_b);
	ft_print_action("rr");
}
