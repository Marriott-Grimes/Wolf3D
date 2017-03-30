/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:33:47 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/21 13:35:58 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t length)
{
	size_t i;

	i = 0;
	while (i < length && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
