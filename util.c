/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:18:24 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/03 16:18:29 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vec	rotate(float a, t_vec v)
{
	t_vec temp;

	temp.x = cos(a) * v.x - sin(a) * v.y;
	temp.y = sin(a) * v.x + cos(a) * v.y;
	return (temp);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec temp;

	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	return (temp);
}

t_vec	sc_mult(float a, t_vec v)
{
	v.x *= a;
	v.y *= a;
	return (v);
}

float	get_dist(t_vec a, t_vec b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

t_vec	normalize(t_vec v)
{
	t_vec	zeero;
	float	len;

	zeero = (t_vec){0, 0};
	len = get_dist(v, zeero);
	if (len == 1.0)
		return (v);
	return (sc_mult(1.0 / len, v));
}
