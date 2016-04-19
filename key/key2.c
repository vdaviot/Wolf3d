/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 16:05:50 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 18:16:30 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		get_map(int x, int y)
{
	static char map[18 * 18] = {-1};

	if (map[0] == -1)
		ft_strcpy(map,
				"111111111111111111"
				"100000000000000001"
				"100001000000000001"
				"100000000000010001"
				"100000000000000001"
				"100000000000000001"
				"100000000000000001"
				"100011111100000001"
				"100000111100000001"
				"100000011100000001"
				"100000001100000001"
				"100000000000000001"
				"100100000000000001"
				"100000000000000001"
				"100000000100000001"
				"100000000000000001"
				"100000000000000001"
				"111111111111111111");
	return (map[x + y * 18] - '0');
}

void	avant(t_ray *ray)
{
	if (get_map(ray->posx + ray->dirx * ray->movespeed, ray->posy) == 0)
		ray->posx += ray->dirx * ray->movespeed;
	if (get_map(ray->posx, ray->posy + ray->diry * ray->movespeed) == 0)
		ray->posy += ray->diry * ray->movespeed;
}

void	arriere(t_ray *ray)
{
	if (get_map(ray->posx - ray->dirx * ray->movespeed, ray->posy) == 0)
		ray->posx -= ray->dirx * ray->movespeed;
	if (get_map(ray->posx, ray->posy - ray->diry * ray->movespeed) == 0)
		ray->posy -= ray->diry * ray->movespeed;
}

void	latgauche(t_ray *ray)
{
	if (get_map(ray->posx + ray->planex * ray->movespeed, ray->posy) == 0)
		ray->posx += ray->planex * ray->movespeed;
	if (get_map(ray->posx, ray->posy + ray->planey * ray->movespeed) == 0)
		ray->posy += ray->planey * ray->movespeed;
}

void	latdroite(t_ray *ray)
{
	if (get_map(ray->posx - ray->planex * ray->movespeed, ray->posy) == 0)
		ray->posx -= ray->planex * ray->movespeed;
	if (get_map(ray->posx, ray->posy - ray->planey * ray->movespeed) == 0)
		ray->posy -= ray->planey * ray->movespeed;
}
