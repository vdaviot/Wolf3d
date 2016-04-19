/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 20:56:39 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/05 20:56:40 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		expose_hook(t_ray *ray)
{
	render(ray);
	mlx_put_image_to_window(ray->mlx, ray->win, ray->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_ray	ray;

	ray.mlx = mlx_init();
	ray.win = mlx_new_window(ray.mlx, WINDOW_W, WINDOW_H, "Wolf3D");
	ray.img = mlx_new_image(ray.mlx, WINDOW_W, WINDOW_H);
	ray.data = mlx_get_data_addr(ray.img, &ray.bpp, &ray.sline, &ray.endian);
	init_var(&ray);
	mlx_hook(ray.win, 2, 1, ft_key_press, &ray);
	mlx_hook(ray.win, 3, 2, ft_key_release, &ray);
	mlx_loop_hook(ray.mlx, move, &ray);
	expose_hook(&ray);
	mlx_loop(ray.mlx);
}
