/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:50:35 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/24 12:50:37 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	char			*b_str;

	i = 0;
	a = (unsigned char)c;
	b_str = (char *)b;
	while (i < len)
	{
		b_str[i] = a;
		i++;
	}
	return (b);
}
