/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 16:15:55 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 16:16:51 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		move(t_ray *ray)
{
	if (ray->key.press == 1)
	{
		if (ray->key.avant == 1)
			avant(ray);
		if (ray->key.arriere == 1)
			arriere(ray);
		if (ray->key.gauche == 1)
			gauche(ray);
		if (ray->key.droite == 1)
			droite(ray);
		if (ray->key.latdroite == 1)
			latdroite(ray);
		if (ray->key.latgauche == 1)
			latgauche(ray);
		if (ray->key.sprint == 1)
			sprint(ray);
		if (ray->key.plus == 1)
			plus(ray);
		ray->begin = clock();
		render(ray);
		ray->end = clock();
	}
	put_info_img(ray);
	return (0);
}

void	put_info_img(t_ray *ray)
{
	mlx_put_image_to_window(ray->mlx, ray->win, ray->img, 0, 0);
	fps(ray);
}

int		ft_key_press(int key_code, t_ray *ray)
{
	if (key_code == FORWARD)
		ray->key.avant = 1;
	if (key_code == BACKWARD)
		ray->key.arriere = 1;
	if (key_code == RIGHT)
		ray->key.droite = 1;
	if (key_code == LEFT)
		ray->key.gauche = 1;
	if (key_code == E)
		ray->key.latdroite = 1;
	if (key_code == Q)
		ray->key.latgauche = 1;
	if (key_code == SPRINT)
		ray->movespeed = 0.5;
	if (key_code == ESC)
	{
		system("killall afplay&");
		exit(0);
	}
	if (key_code == PLUS)
		ray->key.plus = 1;
	if (key_code == STAR)
		ray->rotspeed = 0.05;
	ray->key.press = 1;
	return (0);
}

int		ft_key_release(int key_code, t_ray *ray)
{
	if (key_code == FORWARD)
		ray->key.avant = 0;
	if (key_code == BACKWARD)
		ray->key.arriere = 0;
	if (key_code == RIGHT)
		ray->key.droite = 0;
	if (key_code == LEFT)
		ray->key.gauche = 0;
	if (key_code == E)
		ray->key.latdroite = 0;
	if (key_code == Q)
		ray->key.latgauche = 0;
	if (key_code == SPRINT)
		ray->movespeed = 0.2;
	if (key_code == PLUS)
		ray->key.plus = 0;
	if (!key_code)
		ray->key.press = 0;
	return (0);
}
