/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:11:20 by mgrimes           #+#    #+#             */
/*   Updated: 2016/10/15 16:53:55 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copied(char *temp, int n)
{
	if (n >= 0)
	{
		while (n != 0)
		{
			temp--;
			*temp = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			temp--;
			*temp = '0' - (n % 10);
			n /= 10;
		}
		temp--;
		*temp = '-';
	}
	return (temp);
}

char			*ft_itoa(int n)
{
	char		*need_to_free;
	char		*temp;
	char		*ans;

	if (n == 0)
	{
		ans = ft_strnew(1);
		if (!ans)
			return (NULL);
		ans[0] = '0';
		return (ans);
	}
	need_to_free = ft_strnew(11);
	if (!need_to_free)
		return (NULL);
	temp = need_to_free + 11;
	ans = copied(temp, n);
	free(need_to_free);
	return (ans);
}
