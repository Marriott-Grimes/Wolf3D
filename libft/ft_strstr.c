/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:06:36 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/22 11:06:41 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_from_index(int i, const char *str, const char *to_find)
{
	int j;

	j = 0;
	while (str[i + j] == to_find[j])
	{
		j++;
		if (to_find[j] == 0)
			return (1);
	}
	return (0);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	int i;

	i = 0;
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[i])
	{
		if (compare_from_index(i, str, to_find))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
