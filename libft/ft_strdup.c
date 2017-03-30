/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:01:58 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/24 12:02:27 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *answer;

	answer = (char*)malloc(ft_strlen(str) + 1);
	if (!answer)
		return (NULL);
	answer = ft_strcpy(answer, str);
	return (answer);
}
