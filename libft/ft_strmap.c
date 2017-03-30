/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:01:47 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/21 17:02:25 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *tab, char (*f)(char))
{
	char	*answer;
	int		i;

	i = 0;
	answer = (char*)malloc(sizeof(char) * (ft_strlen(tab) + 1));
	if (!answer)
		return (NULL);
	while (tab[i])
	{
		answer[i] = f(tab[i]);
		i++;
	}
	answer[i] = 0;
	return (answer);
}
