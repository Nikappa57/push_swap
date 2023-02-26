/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:33:03 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/02/23 20:20:13 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issdigit(char *s)
{
	size_t	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	return (1);
}

static int	ft_parse_args_list(int argc, char **argv, t_list **stack_a, int i)
{
	t_list	*tmp;

	while (i < argc)
	{
		if (!ft_issdigit(argv[i]))
			return (ft_print_error());
		tmp = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(stack_a, tmp);
	}
	tmp = NULL;
	return (1);
}

int	ft_parse_args(int argc, char **argv, t_list **stack_a)
{
	char	**args;
	int		args_len;
	int		result;

	if (argc < 2)
		result = 0;
	else if (argc == 2)
	{
		args_len = 0;
		args = ft_split(argv[1], ' ');
		while (args[args_len])
			args_len++;
		result = ft_parse_args_list(args_len, args, stack_a, 0);
		free(args);
	}
	else
		result = ft_parse_args_list(argc, argv, stack_a, 1);
	return (result);
}
