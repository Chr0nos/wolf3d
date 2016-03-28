/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:29:14 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/28 11:45:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** about popper:
** this function is here to find the point on the map where the player will be
** spawned, the x on the map is equivalent to a 0 or a space
** if no spawn point is found the function return -1
*/

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
			if (c->map.b[y].data[x] == MAP_SPAWN)
			{
				c->player.rootpos.x = (double)x + 1;
				c->player.rootpos.y = (double)y + 1;
				c->player.pos = c->player.rootpos;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
