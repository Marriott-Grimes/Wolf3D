/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:05:46 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/21 17:05:53 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *tab, char (*f)(unsigned int, char))
{
	char	*answer;
	int		i;

	i = 0;
	answer = (char*)malloc(sizeof(char) * (ft_strlen(tab) + 1));
	if (!answer)
		return (NULL);
	while (tab[i])
	{
		answer[i] = f(i, tab[i]);
		i++;
	}
	answer[i] = 0;
	return (answer);
}
