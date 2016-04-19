/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:38:11 by vdaviot           #+#    #+#             */
/*   Updated: 2015/06/11 15:38:13 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int		ft_convert(char *buff, int n, int b, int maj)
{
	static	char	*base = "0123456789abcdefghijklmnopqrstuvwxyz";
	int				i;
	unsigned int	tmp;

	i = (n < 0) ? 1 : 0;
	tmp = (n < 0) ? -n : n;
	while (tmp >= (int64_t)b && ((tmp /= b) || 1))
		i++;
	buff[i + 1] = 0;
	tmp = (n < 0) ? -n : n;
	while (tmp >= (int64_t)b && ((buff[i--] = base[tmp % b]
					- ((tmp % b > 9 && maj) ? 32 : 0)) || 1))
	{
		tmp /= b;
		buff[i] = base[tmp % b] - (((tmp % b > 9 && maj)) ? 32 : 0);
	}
	buff[0] = (n < 0) ? '-' : buff[0];
	return (ft_strlen(buff));
}
