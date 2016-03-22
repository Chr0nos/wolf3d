/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:27:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/22 14:32:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include <math.h>

static void		init_deltas_stepdist(t_context *c, t_display *d)
{
	if (d->deltadis.x < 0)
	{
		d->step.x = -1;
		d->sidedist.x = (d->raypos.x - c->x->width) * d->deltadis.x;
	}
	else
	{
		d->step.x = 1;
		d->sidedist.x = (c->x->width + 1 - d->raypos.x) * d->deltadis.x;
	}
	if (d->deltadis.y < 0)
	{
		d->step.y = -1;
		d->sidedist.y = (d->raypos.y - c->x->height) * d->deltadis.y;
	}
	else
	{
		d->step.y = 1;
		d->sidedist.y = (c->x->height+ 1 - d->raypos.y) * d->deltadis.y;
	}
}

static void		init_deltas(t_context *c)
{
	t_display	*d;
	t_posxy		*rd;
	t_point		map;

	d = &c->player.d;
	rd = &d->raydir;
	map.x = (int)d->raypos.x;
	map.y = (int)d->raypos.y;
	d->deltadis.x = sqrt(1 + (rd->y * rd->y) / (rd->x * rd->x));
	d->deltadis.y = sqrt(1 + (rd->x * rd->x) / (rd->y * rd->y));
	init_deltas_stepdist(c, d);
}

void			init_display(t_context *c)
{
	t_display	*d;
	t_point		px;
	int			hit;

	d = &c->player.d;
	d->w = (double)c->x->width;
	px.x = 0;
	while (px.x < c->x->width)
	{
		d->camera_x = 2 * px.x / d->w - 1;
		d->raydir.x = c->player.dir.x + c->player.plane.x * d->camera_x;
		d->raydir.y = c->player.dir.y + c->player.plane.y * d->camera_x;
		px.x++;
	}
	d->raypos.x = c->player.pos.x;
	d->raypos.y = c->player.pos.y;
	init_deltas(c);
	hit = 0;
	/*
	while (!hit)
	{

	}
	*/
}
