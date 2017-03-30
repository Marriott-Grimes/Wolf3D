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

t_wall	find_wall(t_vec offset, t_window *win_ptr)
{
	t_vec	p;
	int		mapsqx;
	int		mapsqy;
	float	boxdistx;
	float	boxdisty;
	int		x_inc;
	int		y_inc;
	int		hit;
	int		side;
	float	perpdist;
	t_wall	ans;

	p = normalize(vec_add(win_ptr->cam, offset));
	mapsqx = (int)win_ptr->pos.x;
	mapsqy = (int)win_ptr->pos.y;
	boxdistx = 0;
	boxdisty = 0;
	hit = 0;
	if (p.x < 0)
	{
		x_inc = -1;
		boxdistx = (mapsqx - win_ptr->pos.x) / p.x;
	}
	else if (p.x > 0)
	{
		x_inc = 1;
		boxdistx = (1.0 - win_ptr->pos.x + mapsqx) / p.x;
	}
	if (p.y < 0)
	{
		y_inc = -1;
		boxdisty = (mapsqy - win_ptr->pos.y) / p.y;
	}
	else if (p.y > 0)
	{
		y_inc = 1;
		boxdisty = (1.0 - win_ptr->pos.y + mapsqy) / p.y;
	}
	while (1)
	{
		if (boxdistx < boxdisty || p.y == 0.0)
		{
			mapsqx += x_inc;
			side = 0;
		}
		else
		{
			mapsqy += y_inc;
			side = 1;
		}
		if (win_ptr->map[mapsqy][mapsqx])
			break ;
		if (side == 0)
			boxdistx += 1.0 / ft_absff(p.x);
		else
			boxdisty += 1.0 / ft_absff(p.y);
	}
	if (side == 0)
		perpdist = (mapsqx - win_ptr->pos.x + (x_inc < 0 ? 1 : 0)) / p.x;
	else
		perpdist = (mapsqy - win_ptr->pos.y + (y_inc < 0 ? 1 : 0)) / p.y;
	ans.dist = perpdist;
	ans.color = win_ptr->map[mapsqy][mapsqx];
	ans.side = side;
	if (!side)
		ans.xslice = win_ptr->pos.y + perpdist * p.y;
	else
		ans.xslice = win_ptr->pos.x + perpdist * p.x;
	ans.xslice -= (int)ans.xslice;
	return (ans);
}
