/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:49:47 by mgrimes           #+#    #+#             */
/*   Updated: 2017/04/03 21:49:58 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		collision(t_vec pos, int map[52][52])
{
	return (map[(int)pos.y][(int)pos.x] ? 1 : 0);
}

int		multipoint_collision(t_vec pos, int map[52][52])
{
	if (!collision(vec_add(pos, (t_vec){0.05, 0.0}), map) &&
		!collision(vec_add(pos, (t_vec){-0.05, 0.0}), map) &&
		!collision(vec_add(pos, (t_vec){0.0, 0.05}), map) &&
		!collision(vec_add(pos, (t_vec){0.0, -0.05}), map))
		return (0);
	return (1);
}

int		movement(t_window *win_ptr)
{
	t_vec		temp;

	if (win_ptr->keys.w)
	{
		temp = vec_add(win_ptr->pos, sc_mult(0.05, win_ptr->cam));
		if (!multipoint_collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (win_ptr->keys.s)
	{
		temp = vec_add(win_ptr->pos, sc_mult(-0.05, win_ptr->cam));
		if (!multipoint_collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (win_ptr->keys.a)
		win_ptr->cam = rotate(PI / 50.0, win_ptr->cam);
	if (win_ptr->keys.d)
		win_ptr->cam = rotate(-PI / 50.0, win_ptr->cam);
	draw_frame(win_ptr);
	return (0);
}
