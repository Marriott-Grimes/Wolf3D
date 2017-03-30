/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 14:27:21 by mgrimes           #+#    #+#             */
/*   Updated: 2016/10/31 14:27:23 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup_until_car(const char *str, char c)
{
	char	*answer;
	int		len;

	len = 0;
	if (str)
	{
		while (str[len] && str[len] != c)
			len++;
	}
	answer = ft_strnew(len);
	if (!answer)
		return (NULL);
	answer = ft_strncpy(answer, str, len);
	return (answer);
}

char	*better_strjoin(char *a, char *b)
{
	char	*ans;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ans = malloc(ft_strlen(a) + ft_strlen(b) + 2);
	if (!ans)
		return (NULL);
	while (a && a[i])
	{
		ans[i] = a[i];
		i++;
	}
	while (b && b[j])
	{
		ans[i + j] = b[j];
		j++;
	}
	ans[i + j] = 0;
	ans[i + j + 1] = 0;
	if (a)
		free(a);
	return (ans);
}

int		search_for_car(char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && str[i] != c)
	{
		i++;
	}
	return (i);
}

int		read_one_line(const int fd, char **str)
{
	char	*buffer;
	int		num_bytes;

	num_bytes = 1;
	while (num_bytes > 0 && search_for_car(*str, '\n') == ft_strlen(*str))
	{
		buffer = ft_strnew(BUFF_SIZE);
		num_bytes = read(fd, buffer, BUFF_SIZE);
		if (num_bytes < 0)
			return (-1);
		*str = better_strjoin(*str, buffer);
		free(buffer);
	}
	return (num_bytes);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*temp;
	int			num_bytes;

	if (!str)
		str = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || read(fd, str, 0) == -1 || line == NULL)
		return (-1);
	num_bytes = read_one_line(fd, &str);
	if (num_bytes == -1)
		return (-1);
	if (search_for_car(str, '\n') < ft_strlen(str))
	{
		*line = strdup_until_car(str, '\n');
		temp = ft_strdup(str + search_for_car(str, '\n') + 1);
		free(str);
		str = temp;
		return (1);
	}
	*line = strdup_until_car(str, 0);
	free(str);
	str = NULL;
	return (ft_strlen(*line) ? 1 : 0);
}
