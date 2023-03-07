/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:17:52 by lgaudino          #+#    #+#             */
/*   Updated: 2023/02/16 18:10:20 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	buffer_size;

	buffer_size = count * size;
	if (buffer_size / size != count)
		return (NULL);
	buffer = malloc(buffer_size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, buffer_size);
	return (buffer);
}
