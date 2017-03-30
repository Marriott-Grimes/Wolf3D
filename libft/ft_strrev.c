/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:11:04 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/27 18:11:05 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	i--;
	while (j <= i)
	{
		dest[j] = src[i - j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
