/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:47:05 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/30 15:47:11 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "./libft/libft.h"

# define PI 3.14159
# define WINWIDTH 1600
# define WINHEIGHT 900
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define FLRCOL 0x00FAFAFA
# define CEILCOL 0x009000A0
# define CEILING 64
# define CAM 32

typedef	struct	s_vec
{
	float		x;
	float		y;
}				t_vec;

typedef	struct	s_keys
{
	int			w:1;
	int			a:1;
	int			s:1;
	int			d:1;
}				t_keys;

typedef	struct	s_window
{
	void		*mlx;
	void		*win;
	void		*buf;
	t_vec		pos;
	t_vec		cam;
	int			wwd;
	int			wht;
	int			bpp;
	int			bytewd;
	int			endian;
	int			textures[5][64 * 64];
	int			map[52][52];
	t_keys		keys;
}				t_window;

typedef	struct	s_wall
{
	float		dist;
	float		xslice;
	char		color;
	char		side;
}				t_wall;

t_vec	rotate(float a, t_vec v);
t_vec	vec_add(t_vec a, t_vec b);
t_vec	sc_mult(float a, t_vec v);
t_vec	normalize(t_vec v);
float	get_dist(t_vec a, t_vec b);
int		*draw_walls(int *image, t_window *win_ptr);
void	draw_frame(t_window *win_ptr);
int		choose_color(char n, char side);
int		collision(t_vec pos, int map[52][52]);
int		movement_keys(int keycode, void *param);
t_wall	find_wall(t_vec offset, t_window *win_ptr);
void	generate_texture(int ans[5][TEXHEIGHT * TEXWIDTH]);
void	load_map(int fd, int map[52][52]);
void	set_hooks(t_window *w);
int		movement(t_window *win_ptr);

#endif
