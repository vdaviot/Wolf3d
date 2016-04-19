/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:09:50 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/22 16:09:52 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include "libft/libft.h"

# define WINDOW_W 800
# define WINDOW_H 600
# define FORWARD 13
# define BACKWARD 1
# define ROT_LEFT 123
# define ROT_RIGHT 124
# define E 12
# define Q 14
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define PLUS 69
# define MOIN 78
# define STAR 67
# define SPRINT 257
# define RED 0xE83233
# define BLUE 0x5AE1FF
# define GREEN 0x69E868
# define YELLOW 0xE5C200
# define GREY 0xABA6B0
# define WHITE 0xFFFFFF
# define ORANGE 0xFF7E13
# define MAPWIDTH 18
# define MAPHEIGHT 18

typedef struct	s_key
{
	int			avant;
	int			arriere;
	int			gauche;
	int			droite;
	int			latgauche;
	int			latdroite;
	int			press;
	int			sprint;
	int			plus;
}				t_key;

typedef	struct	s_ray
{
	void		*mlx;
	void		*win;
	void		*img;
	int			sline;
	int			bpp;
	int			endian;
	char		*data;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		w;
	double		h;
	double		x;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		mapx;
	double		mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		stepx;
	double		stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	double		hline;
	double		drawstart;
	double		drawend;
	double		olddirx;
	double		oldplanex;
	double		rotspeed;
	double		movespeed;
	t_key		key;
	clock_t		begin;
	clock_t		end;
}				t_ray;

void			init_var(t_ray	*ray);
void			init_camera(t_ray *ray);
void			raycast(t_ray *ray);
void			draw(t_ray *ray);
void			render(t_ray *ray);
void			avant(t_ray	*ray);
void			arriere(t_ray *ray);
void			tourner(t_ray *ray);
void			droite(t_ray *ray);
void			gauche(t_ray *ray);
void			latgauche(t_ray *ray);
void			latdroite(t_ray *ray);
int				move(t_ray *ray);
int				ft_key_release(int key_code, t_ray *ray);
int				ft_key_press(int key_code, t_ray *ray);
void			mlx_pixel_put_to_image(t_ray *ray, int x, int y, int color);
int				expose_hook(t_ray *ray);
void			fps(t_ray *ray);
void			sprint(t_ray *ray);
void			plus(t_ray *ray);
int				ft_convert(char *buff, int n, int b, int maj);
void			raycast1(t_ray *ray);
void			raycast2(t_ray *ray);
void			raycast3(t_ray *ray);
void			draw2(t_ray *ray, unsigned int color, double y);
void			put_info_img(t_ray *ray);
int				get_map(int x, int y);

#endif
