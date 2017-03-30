/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 13:17:50 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/24 13:17:54 by mgrimes          ###   ########.fr       */
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

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	little_string_length;

	i = 0;
	little_string_length = ft_strlen(to_find);
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[i] && i <= len - little_string_length)
	{
		if (compare_from_index(i, str, to_find))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
