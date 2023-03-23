/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:45:50 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 22:11:28 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	ft_action_execute_p(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		ft_p_stack(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_p_stack(stack_a, stack_b);
	else
		ft_print_error(stack_a, stack_b);
}

static void	ft_action_execute_s(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ft_s_stack(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_s_stack(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		ft_s_stack(stack_a);
		ft_s_stack(stack_b);
	}
	else
		ft_print_error(stack_a, stack_b);
}

static void	ft_action_execute_r(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 3))
		ft_r_stack(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_r_stack(stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		ft_r_stack(stack_a);
		ft_r_stack(stack_b);
	}
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_rr_stack(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_rr_stack(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		ft_rr_stack(stack_a);
		ft_rr_stack(stack_b);
	}
	else
		ft_print_error(stack_a, stack_b);
}

static void	ft_read_execute(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (*str != '\n')
	{
		if (*str == 'p')
			ft_action_execute_p(stack_a, stack_b, str);
		else if (*str == 's')
			ft_action_execute_s(stack_a, stack_b, str);
		else if (*str == 'r')
			ft_action_execute_r(stack_a, stack_b, str);
		else
			ft_print_error(stack_a, stack_b);
		str = get_next_line(0);
	}
}

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
	ft_read_execute(&stack_a, &stack_b);
	if (!ft_is_sort(stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

// TODO: controllar se serve che stack_b sia vuoto