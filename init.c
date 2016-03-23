/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:27:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 17:32:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <math.h>

/*
** this function calculate the directional vector and the the lenght of
** each segment
*/

static void		init_deltas_stepdist(t_context *c, t_ray *ray)
{
	if (ray->deltadis.x < 0)
	{
		ray->step.x = -1.0f;
		ray->sidedist.x = (ray->pos.x - c->x->width) * ray->deltadis.x;
	}
	else
	{
		ray->step.x = 1.0f;
		ray->sidedist.x = (c->x->width + 1 - ray->pos.x) * ray->deltadis.x;
	}
	if (ray->deltadis.y < 0)
	{
		ray->step.y = -1.0f;
		ray->sidedist.y = (ray->pos.y - c->x->height) * ray->deltadis.y;
	}
	else
	{
		ray->step.y = 1.0f;
		ray->sidedist.y = (c->x->height + 1 - ray->pos.y) * ray->deltadis.y;
	}
}

static t_point		init_ray(t_context *c, t_ray *ray, t_point px)
{
	int			hit;
	int			side;

	hit = 0;
	while (!hit)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadis.x;
			px.x += ray->step.x;
			side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadis.y;
			px.y += ray->step.y;
			side = 1;
		}
		if (check_obstacle(c, px.x, px.y))
		{
			ft_printf("obstacle found on %d %d\n", px.x, px.y);
			hit = 1;
		}
	}
	return (px);
}

static void		init_dda(t_context *c, t_point px)
{
	t_ray	ray;

	ray.pos = c->player.pos;
	ray.dir = c->player.raydir;
	ray.deltadis.x = sqrt(1 + pow(ray.dir.y, 2) / pow(ray.dir.x, 2));
	ray.deltadis.y = sqrt(1 + pow(ray.dir.x, 2) / pow(ray.dir.y, 2));
	init_deltas_stepdist(c, &ray);
	init_ray(c, &ray, px);
}

void			init_display(t_context *c)
{
	const double	w = (double)c->x->width;
	double			camera_x;
	t_posxy			raydir;
	t_posxy			raypos;
	t_point			px;

	px.x = 0;
	while (px.x < c->x->width)
	{
		camera_x = 2.0 * (double)px.x / w - 1.0;
		raydir.x = c->player.dir.x + c->player.plane.x * camera_x;
		raydir.y = c->player.dir.y + c->player.plane.y * camera_x;
		//ft_printf("raydir: x:%d y:%d\n", (int)raydir.x, (int)raydir.y);
		px.x++;
	}
	c->player.raydir = raydir;
	init_dda(c, draw_make_px((int)raypos.x, (int)raypos.y));
}
