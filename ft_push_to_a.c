/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:11:22 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/03 00:09:54 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_move_elm_front_len(int stack_len, int elm_pos)
{
	if (elm_pos < 0)
		return (ft_print_error());
	if (elm_pos <= (int)(stack_len / 2))
		return (elm_pos);
	else
		return (elm_pos - stack_len);
}

static int	ft_find_a_elm(
	t_list *stack_a, t_list *stack_b, int stack_a_len, int b_elm_pos)
{
	int				i;
	int				a_val;
	int				b_val;
	unsigned int	min_diff;
	int				min_a_pos;

	i = 0;
	b_val = ft_stack_elm_val(stack_b, b_elm_pos);
	min_diff = 0;
	min_a_pos = 0;
	while (i < stack_a_len)
	{
		a_val = ft_stack_elm_val(stack_a, i++);
		if (b_val > a_val)
			continue ;
		// printf("%d > %d, Dist: %u\n", a_val, b_val, (unsigned int)(a_val - b_val));
		// printf("CONTROLLO %d\n", a_val);
		// printf("DISTANZA: %u\n", a_val - b_val);
		if ((min_diff > a_val - b_val) || (!min_diff))
		{
			min_diff = a_val - b_val;
			min_a_pos = i - 1;
		}
	}
	// printf("DISTANZA MINIMA %u\n", min_diff);
	return (min_a_pos);
}

static int	ft_push_elm_to_a_len(
	t_list *stack_a, t_list *stack_b, int stack_a_len, int b_elm_pos)
{
	int	rb_n;
	int	ra_n;
	int	a_elm_pos;
	int	stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	a_elm_pos = ft_find_a_elm(stack_a, stack_b, stack_a_len, b_elm_pos);
	if (a_elm_pos == -1)
		return (-1);
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	ra_n = ft_move_elm_front_len(stack_a_len, a_elm_pos);
	if (ra_n == 0
		&& ft_stack_elm_ismax(stack_a, ft_stack_elm_val(stack_b, b_elm_pos)))
	{
		if (ft_stack_elm_ismax(stack_a, ft_stack_elm_val(stack_a, 0)))
			ra_n = 1;
		else
			ra_n = ft_stack_find_min_pos(stack_a);
	}
	if (ra_n > 0 && rb_n > 0)
		return (ft_max(ra_n, rb_n));
	else if (ra_n < 0 && rb_n < 0)
		return (ft_abs(ft_min(ra_n, rb_n)));
	return (ft_abs(ra_n) + ft_abs(rb_n));
}

static void	ft_push_elm_to_a(
	t_list **stack_a, t_list **stack_b, int b_elm_pos, int stack_a_len)
{
	int	rb_n;
	int	ra_n;
	int	a_elm_pos;
	int	stack_b_len;

	stack_b_len = ft_lstsize(*stack_b);
	// printf("RICERCA MINIMO DI %d\n", ft_stack_elm_val(*stack_b, b_elm_pos));
	a_elm_pos = ft_find_a_elm(*stack_a, *stack_b, stack_a_len, b_elm_pos);
	if (a_elm_pos == -1)
		return ;
	// printf("MINIMO: %d\n", ft_stack_elm_val(*stack_a, a_elm_pos));
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	ra_n = ft_move_elm_front_len(stack_a_len, a_elm_pos);
	// printf("RA: %d\n", ra_n);
	if (ra_n == 0
		&& ft_stack_elm_ismax(*stack_a, ft_stack_elm_val(*stack_b, b_elm_pos)))
	{
		// printf("NON FA MOSSE, ");
		if (ft_stack_elm_ismax(*stack_a, ft_stack_elm_val(*stack_a, 0)))
		{
			ra_n = 1;
			// printf(" è l'ultimo e sopra c'è l'ultimo\n");
		}
		else
		{
			ra_n = ft_stack_find_min_pos(*stack_a);
			// printf(" è l'ultimo\n");
		}
	}
	ft_r_best_combo(stack_a, stack_b, ra_n, rb_n);
	ft_pa(stack_a, stack_b);
	// ft_ra_n(stack_a, ra_n);
	// ft_rb_n_pa(stack_a, stack_b, rb_n);
	// TODO combo
}

void	ft_push_to_a(
	t_list **stack_a, t_list **stack_b, int stack_a_len, int stack_b_len)
{
	int	i;
	int	move;
	int	min_move;
	int	min_elm_pos;

	while (stack_b_len)
	{
		i = 0;
		min_move = stack_a_len + stack_b_len;
		while (i < stack_b_len)
		{
			move = ft_push_elm_to_a_len(*stack_a, *stack_b, stack_a_len, i++);
			if (move < min_move && move != -1)
			{
				min_move = move;
				min_elm_pos = i - 1;
			}
		}
		ft_push_elm_to_a(stack_a, stack_b, min_elm_pos, stack_a_len++);
		stack_b_len--;
		// ft_print_stack(*stack_a, *stack_b);
		// printf("-------------------------\n");
	}
	ft_stack_sort(stack_a);
}
