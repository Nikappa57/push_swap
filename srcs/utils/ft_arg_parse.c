/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:33:03 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/27 23:15:41 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issdigit(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	if (ft_strlen(s) > 12)
		return (0);
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	return (1);
}

static int	ft_parse_args_list(int argc, char **argv, t_list **stack_a)
{
	t_list	*tmp;
	int		content;
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!ft_issdigit(argv[i]))
			return (0);
		content = ft_atoi(argv[i++]);
		if ((*stack_a != NULL) && (ft_stack_elm_pos(*stack_a, content) != -1))
			return (0);
		tmp = ft_lstnew(content);
		ft_lstadd_back(stack_a, tmp);
	}
	tmp = NULL;
	return (1);
}

int	ft_parse_args(int *argc, char **argv, t_list **stack_a)
{
	char	**args;
	int		args_len;
	int		result;

	if (*argc == 2)
	{
		args_len = 0;
		args = ft_split(argv[1], ' ');
		while (args[args_len])
			args_len++;
		result = ft_parse_args_list(args_len, args, stack_a);
		*argc = args_len + 1;
		while (--args_len >= 0)
			free(args[args_len]);
		free(args);
	}
	else
		result = ft_parse_args_list(*argc - 1, argv + 1, stack_a);
	return (result);
}

// TODO: error check, test_case 3 
//		penso sia che manca il free(args)
