/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:15:00 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 22:26:04 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_a_len;
	int		stack_b_len;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_parse_args(&argc, argv, &stack_a))
		return (0);
	if (argc - 1 <= 5)
	{
		ft_short_sort(&stack_a, &stack_b, argc - 1);
		ft_print_action(NULL);
		return (0);
	}
	ft_simplify_stack(&stack_a, argc - 1);
	ft_push_to_b(&stack_a, &stack_b, argc - 1);
	stack_a_len = ft_lstsize(stack_a);
	stack_b_len = ft_lstsize(stack_b);
	ft_push_to_a(&stack_a, &stack_b, stack_a_len, stack_b_len);
	ft_print_action(NULL);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
