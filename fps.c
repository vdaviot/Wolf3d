/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:36:36 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 15:36:39 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void		fps(t_ray *ray)
{
	char	buff[0xF00];

	ft_strcpy(buff, "fps: ");
	ft_convert(buff + 5, (int)(1000 / (((ray->end - ray->begin) * 1000)
					/ CLOCKS_PER_SEC)), 10, 0);
	mlx_string_put(ray->mlx, ray->win, 20, 20, WHITE, buff);
}
