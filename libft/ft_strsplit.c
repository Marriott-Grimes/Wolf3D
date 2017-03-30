/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:06:35 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/21 13:33:12 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_next_word(const char *str, char c)
{
	int j;

	j = 0;
	while (str[j] == c && str[j])
		j++;
	return (j);
}

static int	find_end_word(const char *str, char c)
{
	int j;

	j = 0;
	while (str[j] != c && str[j])
		j++;
	return (j);
}

static int	get_word_count(const char *str, char c)
{
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		i += find_next_word(&str[i], c);
		if (find_end_word(&str[i], c) > 0)
		{
			i += find_end_word(&str[i], c);
			word_count++;
		}
	}
	return (word_count);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**ans;

	i = 0;
	j = 0;
	word_count = get_word_count(str, c);
	ans = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (ans == NULL)
		return (NULL);
	ans[word_count] = NULL;
	while (j < word_count)
	{
		i += find_next_word(&str[i], c);
		ans[j] = ft_strnew(find_end_word(&str[i], c));
		ans[j] = ft_strncpy(ans[j], &str[i], find_end_word(&str[i], c));
		i += find_end_word(&str[i], c);
		j++;
	}
	return (ans);
}
