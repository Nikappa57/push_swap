/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:01:14 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 12:01:26 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a)
{
	ft_rr_stack(stack_a);
	ft_print_action("rra");
}

void	ft_rrb(t_list **stack_b)
{
	ft_rr_stack(stack_b);
	ft_print_action("rrb");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rr_stack(stack_a);
	ft_rr_stack(stack_b);
	ft_print_action("rrr");
}
