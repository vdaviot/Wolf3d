/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 16:09:37 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 16:11:49 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	gauche(t_ray *ray)
{
	ray->olddirx = ray->dirx;
	ray->dirx = ray->dirx * cos(ray->rotspeed) - ray->diry * sin(ray->rotspeed);
	ray->diry = ray->olddirx * sin(ray->rotspeed) + ray->diry *
		cos(ray->rotspeed);
	ray->oldplanex = ray->planex;
	ray->planex = ray->planex * cos(ray->rotspeed) - ray->planey *
		sin(ray->rotspeed);
	ray->planey = ray->oldplanex * sin(ray->rotspeed) + ray->planey *
		cos(ray->rotspeed);
}

void	droite(t_ray *ray)
{
	ray->olddirx = ray->dirx;
	ray->dirx = ray->dirx * cos(-ray->rotspeed) - ray->diry *
		sin(-ray->rotspeed);
	ray->diry = ray->olddirx * sin(-ray->rotspeed) + ray->diry *
		cos(-ray->rotspeed);
	ray->oldplanex = ray->planex;
	ray->planex = ray->planex * cos(-ray->rotspeed) - ray->planey *
		sin(-ray->rotspeed);
	ray->planey = ray->oldplanex * sin(-ray->rotspeed) + ray->planey *
		cos(-ray->rotspeed);
}

void	sprint(t_ray *ray)
{
	if (ray->movespeed == 0.2)
		ray->movespeed = 1;
	else
		ray->movespeed = 0.2;
}

void	plus(t_ray *ray)
{
	ray->rotspeed += 1;
}
