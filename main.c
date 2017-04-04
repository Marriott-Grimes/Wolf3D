/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:46:56 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/30 15:46:58 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vec		find_start_pos(int map[52][52])
{
	t_vec p;

	p.y = 1.1;
	while (p.y < 51)
	{
		p.x = 1.1;
		while (p.x < 51)
		{
			if (!map[(int)p.y][(int)p.x])
				return (p);
			p.x++;
		}
		p.y++;
	}
	return (p);
}

t_window	struct_init(int argc, char **argv)
{
	int			fd;
	t_window	wndow;

	wndow.mlx = mlx_init();
	wndow.win = mlx_new_window(wndow.mlx, WINWIDTH, WINHEIGHT, "wolf3d");
	wndow.buf = mlx_new_image(wndow.mlx, WINWIDTH, WINHEIGHT);
	wndow.wwd = WINWIDTH;
	wndow.wht = WINHEIGHT;
	wndow.bpp = 32;
	wndow.endian = 0;
	wndow.bytewd = 4 * WINWIDTH;
	generate_texture(wndow.textures);
	if (argc != 2)
		fd = open("default_map", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	load_map(fd, wndow.map);
	wndow.pos = find_start_pos(wndow.map);
	wndow.cam = (t_vec){0, 1.0};
	return (wndow);
}

int			main(int argc, char **argv)
{
	t_window	wndow;

	wndow = struct_init(argc, argv);
	draw_frame(&wndow);
	set_hooks(&wndow);
	mlx_loop_hook(wndow.mlx, movement, &wndow);
	mlx_loop(wndow.mlx);
	return (0);
}
