/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:11:22 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/11 22:19:59 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// CHUNK
static int	ft_chunk_len(int len)
{
	if (len <= 10)
		return (1);
	if (len <= 100)
		return (2);
	if (len <= 500)
		return (4);
	return (0);
}

static int	ft_is_in_chunk(int all_nbr_len, int chunk, int val)
{
	int			min;
	int			max;
	int			chunk_len;
	int			nbr_per_chunk;

	if (all_nbr_len % 2)
		all_nbr_len++;
	chunk_len = ft_chunk_len(all_nbr_len);
	nbr_per_chunk = all_nbr_len / chunk_len;
	min = nbr_per_chunk * chunk;
	max = min - 1 + nbr_per_chunk;
	if (val <= max && val >= min)
		return (1);
	return (0);
}

int	ft_get_chunk(int val, int all_nbr_len)
{
	int	chunk_len;
	int	chunk;

	chunk = 0;
	chunk_len = ft_chunk_len(all_nbr_len);
	while (!ft_is_in_chunk(all_nbr_len, chunk, val))
		chunk++;
	return (chunk);
}


// TODO: quando fa rrb probabilmente non gli serve portare l'elm sopra, basta che si sotto
static int	ft_move_elm_front_len(int stack_len, int elm_pos)
{
	if (elm_pos < 0)
		return (ft_print_error());
	if (elm_pos <= (int)(stack_len / 2))
		return (elm_pos);
	else
		return (elm_pos - stack_len);
}

static int	ft_find_b_elm(
	t_list *stack_a, t_list *stack_b, int min_elm_pos, int all_nbr_len)
{
	int	i;
	int	tmp_rb;
	int	min_rb;
	int	min_b_pos;
	int	stack_b_len;

	stack_b_len = ft_lstsize(stack_b);
	i = 0;
	min_b_pos = 0;
	min_rb = all_nbr_len;
	while (i < stack_b_len)
	{
		if (ft_is_in_chunk(all_nbr_len, ft_get_chunk(ft_stack_elm_val(
						stack_a, min_elm_pos), all_nbr_len), stack_b->content)
			&& ft_abs(min_rb) > ft_abs(ft_move_elm_front_len(stack_b_len, i)))
		{
			min_rb = ft_move_elm_front_len(stack_b_len, i);
			min_b_pos = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (min_b_pos);
}

static void	ft_push_elm_to_b(
	t_list **stack_a, t_list **stack_b, int min_elm_pos, int all_nbr_len)
{
	int	rb_n;
	int	ra_n;
	int	b_elm_pos;
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = ft_lstsize(*stack_a);
	stack_b_len = ft_lstsize(*stack_b);
	b_elm_pos = ft_find_b_elm(*stack_a, *stack_b, min_elm_pos, all_nbr_len);
	if (b_elm_pos == -1)
		return ;
	rb_n = ft_move_elm_front_len(stack_b_len, b_elm_pos);
	ra_n = ft_move_elm_front_len(stack_a_len, min_elm_pos);
	ft_r_best_combo(stack_a, stack_b, ra_n, rb_n);
	ft_pb(stack_a, stack_b);
}

static int	ft_push_elm_to_b_len(int ra_n, int rb_n)
{
	if (ra_n > 0 && rb_n > 0)
		return (ft_max(ra_n, rb_n));
	else if (ra_n < 0 && rb_n < 0)
		return (ft_abs(ft_min(ra_n, rb_n)));
	return (ft_abs(ra_n) + ft_abs(rb_n));
}

void ft_stack_rmv_elm(t_list **stack, int elm_val)
{
	int		i;
	int		position;
	t_list	*tmp;
	t_list	*prev;

	i = 0;
	position = ft_stack_elm_pos(*stack, elm_val) + 1;
	tmp = *stack;
	prev = *stack;
	while (i < position)
	{
		if (i == 0 && position == 1)
		{
			*stack = (*stack)->next;
			ft_lstdelone(tmp);
		}
		else
		{
			if (i == position - 1 && tmp)
			{
				prev->next = tmp->next;
				ft_lstdelone(tmp);
			}
			else
			{
				prev = tmp;
				if (prev == NULL)
					break ;
				tmp = tmp->next;
			}
		}
		i++;
	}
}

static int	ft_min_elm(t_list *stack_a, t_list *stack_b,
	t_list *nolis_list, int all_nbr_len)
{
	int			rb_n;
	int			a_elm_pos;
	int			tmp_move;
	int			min_move;
	int			min_elm;
	int			stack_b_len;
	int 		stack_a_len;

	stack_a_len = ft_lstsize(stack_a);
	stack_b_len = ft_lstsize(stack_b);
	min_move = stack_a_len + stack_b_len; // ALL NBR = stack_a_len + stack_b_len
	while (nolis_list)
	{
		a_elm_pos = ft_stack_elm_pos(stack_a, nolis_list->content);
		rb_n = ft_move_elm_front_len(stack_b_len, ft_find_b_elm(
					stack_a, stack_b, a_elm_pos, all_nbr_len));
		tmp_move = ft_push_elm_to_b_len(ft_move_elm_front_len(stack_a_len,
					a_elm_pos), rb_n);
		if (tmp_move < min_move && tmp_move != -1)
		{
			min_move = tmp_move;
			min_elm = nolis_list->content;
		}
		nolis_list = nolis_list->next;
	}
	return (min_elm);
}

// LIS

static void	ft_nolis(t_list *stack_a, int v_len, t_list **nolis)
{
	int	i;
	int	*v;
	int	lis_max;
	int	*lis_arr;

	v = ft_copy_stack(stack_a, v_len);
	lis_arr = ft_lis_arr(v, v_len);
	lis_max = ft_lis_max(lis_arr, v_len);
	while (v_len > 0)
	{
		if (lis_arr[--v_len] == lis_max)
			lis_max--;
		else
			ft_lstadd_front(nolis, ft_lstnew(v[v_len]));
	}
	free(lis_arr);
	free(v);
}

void	ft_push_to_b(
	t_list **stack_a, t_list **stack_b, int stack_a_len)
{
	int		nolis_len;
	int		min_elm;
	int		all_nbr_len;
	int		stack_b_len;
	t_list	*nolis_list;

	stack_b_len = 0;
	all_nbr_len = stack_a_len;
	nolis_list = NULL;
	ft_nolis(*stack_a, stack_a_len, &nolis_list);
	nolis_len = ft_lstsize(nolis_list);
	// printf("NOLIS LEN: %d\nNOLIS:\n", nolis_len);
	// ft_print_stack(nolis_list, NULL);
	while (nolis_len > 0)
	{
		// printf("-------------------\n");
		// printf("NOLIS LEN: %d\nNOLIS:\n", nolis_len);
		// ft_print_stack(nolis_list, NULL);
		min_elm = ft_min_elm(
				*stack_a, *stack_b, nolis_list, all_nbr_len);
		ft_stack_rmv_elm(&nolis_list, min_elm);
		// printf("ELEMENTO DA SPOSTARE: %d\n", min_elm);
		ft_push_elm_to_b(stack_a, stack_b, ft_stack_elm_pos(
				*stack_a, min_elm), all_nbr_len);
		stack_b_len++;
		stack_a_len--;
		nolis_len--;
	}
	ft_lstclear(&nolis_list);
}

// TODO: ottimizzare push dell'ultimo (anche ultimi 2??)