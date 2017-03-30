/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 18:50:38 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/21 18:50:40 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *answer;

	answer = (char*)malloc(sizeof(char) * (len + 1));
	if (!answer)
		return (NULL);
	answer = ft_strncpy(answer, &s[start], len);
	answer[len] = 0;
	return (answer);
}
