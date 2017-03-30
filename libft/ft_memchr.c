/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 13:24:30 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/25 13:24:32 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	a;

	i = 0;
	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
