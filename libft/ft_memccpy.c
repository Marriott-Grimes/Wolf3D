/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:12:08 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/24 16:12:10 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;
	unsigned char	a;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	a = (unsigned char)c;
	while (i < n && source[i] != a)
	{
		dest[i] = source[i];
		i++;
	}
	if (source[i] == a)
	{
		dest[i] = a;
		return ((void *)(dest + i + 1));
	}
	return (NULL);
}
