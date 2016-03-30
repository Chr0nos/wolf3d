/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:36:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 18:29:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** returns:
** 0 = empty cell
** 1 = basic wall
** 2 = other walls
** 3 = invisible wall
** 4 = map external border
*/

int		check_obstacle(t_context *c, int x, int y, t_mode mode)
{
	char	p;

	if ((y < 0) || (c->map.lines <= (unsigned int)y))
		return (4);
	else if ((x < 0) || (c->map.b[y].size <= x))
		return (4);
	p = c->map.b[y].data[x];
	if ((p == ' ') || (p == MAP_SPAWN))
		return (0);
	if (p == MAP_INVISIBLE_WALL)
	{
		if (c->flags & FLAG_SHOWINVISIBLE)
			return (3);
		return ((mode == CHECK_WALK) ? 1 : 0);
	}
	if (p == MAP_SECRET_WALL)
		return ((mode == CHECK_WALK) ? 0 : MAP_SECRET_WALL);
	return (p - '0');
}
