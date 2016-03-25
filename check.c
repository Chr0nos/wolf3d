/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:36:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 13:45:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		check_obstacle(t_context *c, int x, int y, t_mode mode)
{
	char	p;

	if ((y < 0) || (c->map.lines <= (unsigned int)y))
		return (-1);
	else if ((x < 0) || (c->map.b[y].size <= x))
		return (-1);
	p = c->map.b[y].data[x];
	if ((p == ' ') || (p == MAP_SPAWN))
		return (0);
	if (p == MAP_INVISIBLE_WALL)
		return ((mode == CHECK_WALK) ? 1 : 0 );
	return (p - '0');
}
