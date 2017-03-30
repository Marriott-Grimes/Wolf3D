/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:14:26 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/27 14:14:27 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_max(ft_strlen(s) - 1, 0);
	while (ISWHITESPACE(s[i]))
		i++;
	while (ISWHITESPACE(s[j]) && j >= 0)
		j--;
	if (i < j || ft_strlen(s) == 1)
	{
		str = ft_strnew(j - i + 1);
		if (!str)
			return (NULL);
		str = ft_strncpy(str, &s[i], j - i + 1);
		return (str);
	}
	else
		return (ft_strnew(0));
}
