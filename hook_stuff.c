#include "wolf.h"

int		collision(t_vec pos, int map[52][52])
{
	return (map[(int)pos.y][(int)pos.x] ? 1 : 0);
}

int		movement(t_window *win_ptr)
{
	t_vec		temp;

	if (win_ptr->keys.w)
	{
		temp = vec_add(win_ptr->pos, sc_mult(0.05, win_ptr->cam));
		if (!collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (win_ptr->keys.s)
	{
		temp = vec_add(win_ptr->pos, sc_mult(-0.05, win_ptr->cam));
		if (!collision(temp, win_ptr->map))
			win_ptr->pos = temp;
	}
	if (win_ptr->keys.a)
		win_ptr->cam = rotate(PI / 50.0, win_ptr->cam);
	if (win_ptr->keys.d)
		win_ptr->cam = rotate(-PI / 50.0, win_ptr->cam);
	draw_frame(win_ptr);
	return (0);
}


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

