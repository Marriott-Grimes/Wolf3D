/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:01:44 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/25 14:01:46 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*mem_area;

	i = 0;
	mem_area = (unsigned char *)malloc(sizeof(char) * size);
	if (!mem_area)
		return (NULL);
	while (i < size)
	{
		mem_area[i] = 0;
		i++;
	}
	return ((void *)mem_area);
}
