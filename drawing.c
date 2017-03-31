/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:26:05 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/07 14:26:07 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		draw_slice(t_wall wall, int y, int line_ht,
					int txtr[5][TEXHEIGHT * TEXWIDTH])
{
	int ans;
	int slice;

	ans = 64.0 / line_ht * (y - (WINHEIGHT - line_ht) / 2.0);
	slice = 64.0 * wall.xslice;
	return (txtr[wall.color - 1][TEXHEIGHT * slice + ans]);
}

int		*draw_walls(int *image, t_window *win_ptr)
{
	int		x;
	int		y;
	int		line_ht;
	t_vec	offset;
	t_wall	wall;

	offset = rotate(-PI / 2.0, win_ptr->cam);
	x = 0;
	while (x < WINWIDTH)
	{
		wall = find_wall(sc_mult(2.2 * x / WINWIDTH - 1.1, offset), win_ptr);
		y = 0;
		while (y < WINHEIGHT)
		{
			// line_ht = ft_min(WINHEIGHT, (int)(WINHEIGHT / wall.dist));
			line_ht = (int)(WINHEIGHT / wall.dist);
			if ((WINHEIGHT - line_ht) / 2 < y && y < (WINHEIGHT + line_ht) / 2
				&& 0 < y && y < WINHEIGHT)
				image[x + y * WINWIDTH] = draw_slice(wall, y, line_ht, win_ptr->textures);
			y++;
		}
		x++;
	}
	return (image);
}

void	draw_frame(t_window *win_ptr)
{
	int x;
	int *image;

	image = (int *)mlx_get_data_addr(win_ptr->buf, &(win_ptr->bpp),
									&(win_ptr->bytewd), &(win_ptr->endian));
	x = 0;
	while (x < WINWIDTH * WINHEIGHT / 2)
		image[x++] = FLRCOL;
	while (x < WINWIDTH * WINHEIGHT)
		image[x++] = CEILCOL;
	image = draw_walls(image, win_ptr);
	mlx_put_image_to_window(win_ptr->mlx, win_ptr->win, win_ptr->buf, 0, 0);
}
