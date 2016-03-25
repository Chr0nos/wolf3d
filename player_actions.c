/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:43:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 13:40:10 by snicolet         ###   ########.fr       */
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
	double		o[2];

	o[0] = cos(rotate_speed);
	o[1] = sin(rotate_speed);
	dir = &c->player.dir;
	olddir = c->player.dir;
	dir->x = dir->x * o[0] - dir->y * o[1];
	dir->y = olddir.x * o[1] + dir->y * o[0];
	oldplane = c->player.plane;
	plane = &c->player.plane;
	plane->x = plane->x * o[0] - plane->y * o[1];
	plane->y = oldplane.x * o[1] + plane->y * o[0];
}

void	player_forward(t_context *c, double speed)
{
	t_posxy		np;
	t_posxy		rate;

	rate.x = c->player.dir.x * speed;
	rate.y = c->player.dir.y * speed;
	np.x = c->player.pos.x + rate.x;
	np.y = c->player.pos.y + rate.y;
	if (!check_obstacle(c, (int)np.x, (int)c->player.pos.y, CHECK_WALK))
		c->player.pos.x = np.x;
	if (!check_obstacle(c, (int)np.x, (int)np.y, CHECK_WALK))
		c->player.pos.y = np.y;
}

void	player_crab(t_context *c, double speed)
{
	t_posxy		np;

	np.x = c->player.pos.x + c->player.plane.x * speed;
	np.y = c->player.pos.y + c->player.plane.y * speed;
	if (!check_obstacle(c, (int)np.x, (int)c->player.pos.y, CHECK_WALK))
		c->player.pos.x = np.x;
	if (!check_obstacle(c, (int)np.x, (int)np.y, CHECK_WALK))
		c->player.pos.y = np.y;
}
