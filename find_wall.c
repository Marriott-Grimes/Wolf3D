/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:27:19 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/07 14:27:22 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float	ft_absff(float n)
{
	return (n > 0 ? n : -n);
}

t_blah	set_loop_vars(t_window *win_ptr)
{
	t_blah d;

	d.mapsqx = (int)win_ptr->pos.x;
	d.mapsqy = (int)win_ptr->pos.y;
	d.boxdistx = 0.0;
	d.boxdisty = 0.0;
	d.x_inc = 1;
	d.y_inc = 1;
	return (d);
}

t_blah	find_wall_part_2(t_blah d, t_window *win_ptr, t_vec p)
{
	if (p.x < 0)
	{
		d.x_inc = -1;
		d.boxdistx = (d.mapsqx - win_ptr->pos.x) / p.x;
	}
	else if (p.x > 0)
	{
		d.x_inc = 1;
		d.boxdistx = (1.0 - win_ptr->pos.x + d.mapsqx) / p.x;
	}
	if (p.y < 0)
	{
		d.y_inc = -1;
		d.boxdisty = (d.mapsqy - win_ptr->pos.y) / p.y;
	}
	else if (p.y > 0)
	{
		d.y_inc = 1;
		d.boxdisty = (1.0 - win_ptr->pos.y + d.mapsqy) / p.y;
	}
	return (d);
}

t_blah	find_wall_loop(t_blah d, t_window *win_ptr, t_vec p)
{
	while (1)
	{
		if (d.boxdistx < d.boxdisty || p.y == 0.0)
		{
			d.mapsqx += d.x_inc;
			d.wall.side = 0;
		}
		else
		{
			d.mapsqy += d.y_inc;
			d.wall.side = 1;
		}
		if (win_ptr->map[d.mapsqy][d.mapsqx])
			break ;
		if (d.wall.side == 0)
			d.boxdistx += 1.0 / ft_absff(p.x);
		else
			d.boxdisty += 1.0 / ft_absff(p.y);
	}
	return (d);
}

t_wall	find_wall(t_vec offset, t_window *win_ptr)
{
	t_vec	p;
	t_blah	d;

	p = normalize(vec_add(win_ptr->cam, offset));
	d = set_loop_vars(win_ptr);
	d = find_wall_part_2(d, win_ptr, p);
	d = find_wall_loop(d, win_ptr, p);
	if (d.wall.side == 0)
		d.wall.dist = (d.mapsqx - win_ptr->pos.x + (d.x_inc < 0 ? 1 : 0)) *
						(win_ptr->cam.x + p.y / p.x * win_ptr->cam.y);
	else
		d.wall.dist = (d.mapsqy - win_ptr->pos.y + (d.y_inc < 0 ? 1 : 0)) *
						(win_ptr->cam.y + p.x / p.y * win_ptr->cam.x);
	d.wall.color = win_ptr->map[d.mapsqy][d.mapsqx];
	if (!d.wall.side)
		d.wall.xslice = win_ptr->pos.y +
		(d.mapsqx - win_ptr->pos.x + (d.x_inc < 0 ? 1 : 0)) / p.x * p.y;
	else
		d.wall.xslice = win_ptr->pos.x +
		(d.mapsqy - win_ptr->pos.y + (d.y_inc < 0 ? 1 : 0)) / p.y * p.x;
	d.wall.xslice -= (int)d.wall.xslice;
	return (d.wall);
}
