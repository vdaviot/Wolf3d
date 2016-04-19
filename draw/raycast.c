/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 20:56:52 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/05 20:56:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	raycast1(t_ray *ray)
{
	ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry) / (ray->raydirx *\
		ray->raydirx));
	ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx) / (ray->raydiry *\
	ray->raydiry));
	ray->hit = 0;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->rayposx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->rayposx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->rayposy) * ray->deltadisty;
	}
}

void	raycast2(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->stepx > 0)
				ray->side = 1;
			else
				ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->stepy > 0)
				ray->side = 3;
			else
				ray->side = 2;
		}
		if (get_map(ray->mapx, ray->mapy) > 0)
			ray->hit = 1;
	}
}

void	raycast3(t_ray *ray)
{
	if (ray->side < 2)
		ray->perpwalldist = fabs((ray->mapx - ray->rayposx + \
			(1.f - ray->stepx) / 2.f) / ray->raydirx);
	else
		ray->perpwalldist = fabs((ray->mapy - ray->rayposy + \
			(1.f - ray->stepy) / 2.f) / ray->raydiry);
	ray->hline = fabs(ray->h / ray->perpwalldist);
	ray->drawstart = (-ray->hline / 2 + ray->h / 2);
	ray->drawend = (ray->hline / 2 + ray->h / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= ray->h)
		ray->drawend = ray->h - 1;
}

void	draw(t_ray *ray)
{
	unsigned int	color;
	double			y;

	y = ray->drawstart;
	while (y < ray->drawend)
	{
		color = ORANGE;
		if (ray->side == 1)
			color = YELLOW;
		if (ray->side == 2)
			color = GREEN;
		if (ray->side == 3)
			color = RED;
		mlx_pixel_put_to_image(ray, ray->x, y, color);
		if (y == ray->drawend - 1)
			mlx_pixel_put_to_image(ray, ray->x, y, 0x000000);
		y++;
	}
	draw2(ray, color, y);
}

void	draw2(t_ray *ray, unsigned int color, double y)
{
	static	double	oldmx = 0;
	static	double	oldmy = 0;

	if (ray->mapy != oldmy || ray->mapx != oldmx)
	{
		oldmy = ray->mapy;
		oldmx = ray->mapx;
		color = 0x000000;
		y = ray->drawstart;
		while (y < ray->drawend)
		{
			mlx_pixel_put_to_image(ray, ray->x, y, color);
			y++;
		}
	}
	if (ray->drawend < 0)
		ray->drawend = ray->h;
	y = ray->drawend;
	while (y < ray->h)
	{
		mlx_pixel_put_to_image(ray, ray->x, y, GREY);
		mlx_pixel_put_to_image(ray, ray->x, ray->h - y - 1, BLUE);
		y++;
	}
}
