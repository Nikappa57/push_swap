/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:33:03 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/03/23 22:20:14 by lorenzogaud      ###   ########.fr       */
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

static int	ft_parse_args_list(int argc, char **argv, t_list **stack_a, int i)
{
	t_list	*tmp;
	int		content;

	while (i < argc)
	{
		if (!ft_issdigit(argv[i]))
			return (ft_print_error(stack_a, NULL));
		content = ft_atoi(argv[i++]);
		if ((*stack_a != NULL) && (ft_stack_elm_pos(*stack_a, content) != -1))
			return (ft_print_error(stack_a, NULL));
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

	if (*argc < 2)
		result = 0;
	else if (*argc == 2)
	{
		args_len = 0;
		args = ft_split(argv[1], ' ');
		while (args[args_len])
			args_len++;
		result = ft_parse_args_list(args_len, args, stack_a, 0);
		free(args);
		*argc = args_len + 1;
	}
	else
		result = ft_parse_args_list(*argc, argv, stack_a, 1);
	return (result);
}