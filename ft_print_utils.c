/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:51:24 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/20 14:15:20 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
	return (0);
}

static char	*ft_get_action_combo(char *action1, char *action2)
{
	if (!action1 || !action2)
		return (NULL);
	if ((!ft_strncmp(action1, "sa", 2) && !ft_strncmp(action2, "sb", 2))
		|| (!ft_strncmp(action1, "sb", 2) && !ft_strncmp(action2, "sa", 2)))
		return ("ss");
	if ((!ft_strncmp(action1, "ra", 2) && !ft_strncmp(action2, "rb", 2))
		|| (!ft_strncmp(action1, "rb", 2) && !ft_strncmp(action2, "ra", 2)))
		return ("rr");
	if ((!ft_strncmp(action1, "rra", 3) && !ft_strncmp(action2, "rrb", 3))
		|| (!ft_strncmp(action1, "rrb", 3) && !ft_strncmp(action2, "rra", 3)))
		return ("rrr");
	if ((!ft_strncmp(action1, "rb", 2) && !ft_strncmp(action2, "rrr", 3))
		|| (!ft_strncmp(action1, "rrr", 3) && !ft_strncmp(action2, "rb", 2)))
		return ("rra");
	if ((!ft_strncmp(action1, "ra", 2) && !ft_strncmp(action2, "rrr", 3))
		|| (!ft_strncmp(action1, "rrr", 3) && !ft_strncmp(action2, "ra", 2)))
		return ("rrb");
	return (NULL);
}

static int	ft_action_check_useless(char *action1, char *action2)
{
	if (!action1 || !action2)
		return (0);
	if ((!ft_strncmp(action1, "ra", 2) && !ft_strncmp(action2, "rra", 3))
		|| (!ft_strncmp(action1, "rra", 3) && !ft_strncmp(action2, "ra", 2))
		|| !ft_strncmp(action1, "rb", 2) && !ft_strncmp(action2, "rrb", 3)
		|| (!ft_strncmp(action1, "rrb", 3) && !ft_strncmp(action2, "rb", 2)))
		return (1);
	if ((!ft_strncmp(action1, "rr", 3) && !ft_strncmp(action2, "rrr", 3))
		|| (!ft_strncmp(action1, "rrr", 3) && !ft_strncmp(action2, "rr", 3)))
		return (1);
	if ((!ft_strncmp(action1, "pa", 2) && !ft_strncmp(action2, "pb", 2))
		|| (!ft_strncmp(action1, "pb", 2) && !ft_strncmp(action2, "pa", 2)))
		return (1);
	return (0);
}

static void	ft_fix_longcombo(char **action1, char **action2)
{
	if (!*action1 || !*action2)
		return ;
	if ((!ft_strncmp(*action1, "rra", 3) && !ft_strncmp(*action2, "rrr", 3))
		|| (!ft_strncmp(*action1, "rrb", 3) && !ft_strncmp(*action2, "rrr", 3)))
		ft_strswap(action1, action2);
}

void	ft_print_action(char *last_action)
{
	static char	*previus_action;
	char		*combo;

	if (!previus_action)
		previus_action = last_action;
	else
	{
		combo = ft_get_action_combo(previus_action, last_action);
		ft_fix_longcombo(&previus_action, &last_action);
		if (combo)
			previus_action = combo;
		else if (ft_action_check_useless(previus_action, last_action))
			previus_action = NULL;
		else
		{
			ft_putstr_fd(previus_action, 1);
			ft_putchar_fd('\n', 1);
			previus_action = last_action;
		}
	}
}
