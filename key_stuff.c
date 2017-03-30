/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:26:15 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/07 14:26:16 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		collision(t_vec pos, int map[52][52])
{
	return (map[(int)pos.y][(int)pos.x] ? 1 : 0);
}

int		movement_keys(int keycode, void *param)
{
	t_window	*win_ptr;
	t_vec		temp;

	win_ptr = (t_window *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
	{
		temp = vec_add(win_ptr->pos, sc_mult(0.25, win_ptr->cam));
		if (!collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (keycode == 125)
	{
		temp = vec_add(win_ptr->pos, sc_mult(-0.25, win_ptr->cam));
		if (!collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (keycode == 123)
		win_ptr->cam = rotate(PI / 8.0, win_ptr->cam);
	if (keycode == 124)
		win_ptr->cam = rotate(-PI / 8.0, win_ptr->cam);
	printf("%f %f --- %f %f\n\n", win_ptr->pos.x, win_ptr->pos.y, win_ptr->cam.x, win_ptr->cam.y);
	draw_frame(win_ptr);
	return (0);
}
