/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:35:14 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/18 11:59:46 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_p_stack(stack_b, stack_a);
	ft_print_action("pa");
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	ft_p_stack(stack_a, stack_b);
	ft_print_action("pb");
}
