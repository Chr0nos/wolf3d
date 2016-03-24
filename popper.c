/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:29:14 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 15:38:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		popper(t_context *c)
{
	int	x;
	int	y;

	y = 0;
	while (y < (int)c->map.lines)
	{
		x = 0;
		while (x < c->map.b[y].size)
		{
			if (c->map.b[y].data[x] == 'x')
			{
				c->player.pos.x = (double)x;
				c->player.pos.y = (double)y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
