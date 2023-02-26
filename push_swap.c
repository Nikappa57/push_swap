/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:15:00 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/26 01:48:34 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_parse_args(argc, argv, &stack_a))
		return (0);
	ft_print_stack(stack_a, stack_b);
	ft_move_nolis_to_b(&stack_a, &stack_b, argc - 1);
	ft_print_stack(stack_a, stack_b);
	ft_print_action(NULL);
	return (0);
}

// TODO CHECK IF SORTED
// TODO SIMPLIFY ARRAY (?)
// TODO FT_ACTION_PUSH
// ft_pa(**stack_a) ft_pb(**stack b)
// ft_pa_elm(**stack_a, int elm_i)
// ft_pb_elm(**stack_b, int elm_i)5
// ft_pa_elm_pos(**stack_b, int elm_a, int pos_b) (??)
