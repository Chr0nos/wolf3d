/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:43:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 11:55:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

void	player_rotate(t_context *c, double rotate_speed)
{
	t_posxy		olddir;
	t_posxy		oldplane;
	t_posxy		*dir;
	t_posxy		*plane;

	rotate_speed = 0.5f;
	dir = &c->player.dir;
	olddir = c->player.dir;
	dir->x = dir->x * cos(rotate_speed) - dir->y * sin(rotate_speed);
	dir->y = olddir.x * sin(rotate_speed) + dir->y * cos(rotate_speed);
	oldplane = c->player.plane;
	plane = &c->player.plane;
	plane->x = plane->x * cos(rotate_speed) - plane->y * sin(rotate_speed);
	plane->y = oldplane.x * sin(rotate_speed) + plane->y * cos(rotate_speed);
}
