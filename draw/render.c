/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:45:50 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 15:45:52 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	render(t_ray *ray)
{
	ray->x = 0;
	while (ray->x <= WINDOW_W)
	{
		init_camera(ray);
		ray->mapx = (int)ray->rayposx;
		ray->mapy = (int)ray->rayposy;
		raycast1(ray);
		raycast2(ray);
		raycast3(ray);
		draw(ray);
		ray->x++;
	}
}

void	mlx_pixel_put_to_image(t_ray *ray, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WINDOW_W * WINDOW_H * ray->bpp / 8;
	if (x < 0 || y < 0 || y * ray->sline + x * ray->bpp / 8 > img_size
		|| x >= ray->sline / (ray->bpp / 8) || y >= img_size / ray->sline)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = ray->bpp / 8;
	ray->data[y * ray->sline + x * bit_pix] = color1;
	ray->data[y * ray->sline + x * bit_pix + 1] = color2;
	ray->data[y * ray->sline + x * bit_pix + 2] = color3;
}

void	init_var(t_ray *ray)
{
	ray->posx = 12;
	ray->posy = 11;
	ray->dirx = -1;
	ray->diry = 0;
	ray->planex = 0;
	ray->planey = 1;
	ray->w = WINDOW_W;
	ray->h = WINDOW_H;
	ray->movespeed = 0.2;
	ray->rotspeed = 0.05;
	system("afplay music/hexagon.mp3&");
}

void	init_camera(t_ray *ray)
{
	ray->camerax = (2.f * ray->x / (double)ray->w) - 1.f;
	ray->rayposx = ray->posx;
	ray->rayposy = ray->posy;
	ray->raydirx = ray->dirx + ray->planex * ray->camerax;
	ray->raydiry = ray->diry + ray->planey * ray->camerax;
}
