/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:50:40 by mgrimes           #+#    #+#             */
/*   Updated: 2017/04/03 21:50:43 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press_hook(int key, void *param)
{
	t_window *win_ptr;

	win_ptr = (t_window *)param;
	if (key == 0)
		win_ptr->keys.a = 1;
	if (key == 1)
		win_ptr->keys.s = 1;
	if (key == 2)
		win_ptr->keys.d = 1;
	if (key == 13)
		win_ptr->keys.w = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int		key_release_hook(int key, void *param)
{
	t_window *win_ptr;

	win_ptr = (t_window *)param;
	if (key == 0)
		win_ptr->keys.a = 0;
	if (key == 1)
		win_ptr->keys.s = 0;
	if (key == 2)
		win_ptr->keys.d = 0;
	if (key == 13)
		win_ptr->keys.w = 0;
	return (0);
}

int		exit_hook(int key, void *param)
{
	(void)key;
	(void)param;
	exit(0);
	return (0);
}

void	set_hooks(t_window *w)
{
	mlx_do_key_autorepeatoff(w->mlx);
	mlx_hook(w->win, 2, 0, key_press_hook, w);
	mlx_hook(w->win, 3, 0, key_release_hook, w);
	mlx_hook(w->win, 17, 0, exit_hook, w);
}
