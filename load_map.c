#include "wolf.h"

void	read_line(char *line, int map[52])
{
	int i;

	i = 1;
	while (i < 51)
	{
		while (*line == ' ')
			line++;
		if (*line)
			map[i] = ft_atoi(line);
		else
			map[i] = 1;
		while (*line && *line != ' ')
			line++;
		i++;
	}
}

void		load_map(int fd, int map[52][52])
{
	int		x;
	int		y;
	int		eof;
	char	*line;

	eof = 1;
	y = 0;
	while (y < 52)
	{
		x = 0;
		while (x < 52)
		{
			map[y][x] = 1;
			x++;
		}
		y++;
	}
	y = 1;
	while (eof && y < 51)
	{
		eof = get_next_line(fd, &line);
		read_line(line, map[y]);
		y++;
	}
}
