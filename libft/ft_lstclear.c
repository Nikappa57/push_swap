/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:43:46 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/06 20:13:28 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	if (!*lst)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next);
	ft_lstdelone(*lst);
	*lst = NULL;
}
