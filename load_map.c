#include "wolf.h"

void		read_line(char *line, int map[52], char *test)
{
	int i;

	i = 1;
	if (line == NULL || !ft_strcmp(line, ""))
		return ;
	while (i < 51)
	{
		while (*line == ' ')
			line++;
		if (*line)
		{
			if (*line == '0')
				*test = 1;
			if (*line < '0' || *line > '4')
				map[i] = 1;
			else
				map[i] = ft_atoi(line);
		}
		while (*line && *line != ' ')
			line++;
		i++;
	}
}

void		set_map(int map[52][52])
{
	int x;
	int y;

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
}

void		load_map(int fd, int map[52][52])
{
	int		y;
	int		eof;
	char	*line;
	char	test;

	eof = 1;
	test = 0;
	if (fd < 0 || read(fd, &test, 0) == -1)
	{
		ft_putstr("bad file :(\n");
		exit(0);
	}
	set_map(map);
	y = 1;
	while (eof && y < 51)
	{
		eof = get_next_line(fd, &line);
		read_line(line, map[y], &test);
		y++;
	}
	if (!test)
	{
		ft_putstr("No empty tiles :(\n");
		exit(0);
	}
}
