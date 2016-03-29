/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:27:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/29 21:00:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

/*
** this function calculate the directional vector and the the lenght of
** each segment
*/

static void		init_deltas_stepdist(t_ray *ray, t_point px)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1.0;
		ray->sidedist.x = (ray->pos.x - (double)px.x) * ray->deltadis.x;
	}
	else
	{
		ray->step.x = 1.0;
		ray->sidedist.x = ((double)px.x + 1.0 - ray->pos.x) * ray->deltadis.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1.0;
		ray->sidedist.y = (ray->pos.y - (double)px.y) * ray->deltadis.y;
	}
	else
	{
		ray->step.y = 1.0;
		ray->sidedist.y = ((double)px.y + 1.0 - ray->pos.y) * ray->deltadis.y;
	}
}

/*
** return the t_point where a wall is encountred
*/

static t_point	init_ray(t_context *c, t_ray *ray, t_point px)
{
	int			hit;

	hit = 0;
	while (!hit)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadis.x;
			px.x += (int)ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadis.y;
			px.y += (int)ray->step.y;
			ray->side = 1;
		}
		if ((ray->obstacle = check_obstacle(c, px.x, px.y, CHECK_RAY)) != 0)
			hit = 1;
	}
	return (px);
}

static void		init_dda(t_context *c, t_point px, t_ray *ray)
{
	ray->pos = c->player.pos;
	ray->dir = c->player.raydir;
	ray->deltadis.x = sqrt(1 + pow(ray->dir.y, 2) / pow(ray->dir.x, 2));
	ray->deltadis.y = sqrt(1 + pow(ray->dir.x, 2) / pow(ray->dir.y, 2));
	init_deltas_stepdist(ray, px);
	px = init_ray(c, ray, px);
	if (ray->side == 0)
		ray->dist = fabs(((double)px.x - ray->pos.x +
			(1.0 - ray->step.x) / 2.0) / ray->dir.x);
	else
		ray->dist = fabs(((double)px.y - ray->pos.y +
			(1.0 - ray->step.y) / 2.0) / ray->dir.y);
	ray->pos.x = (double)px.x;
	ray->pos.y = (double)px.y;
}

void			init_display(t_context *c)
{
	const double	w = (double)c->x->width;
	double			camera_x;
	t_point			px;
	t_ray			ray;

	ray.obstacle = 0;
	px.x = 0;
	while (px.x < c->x->width)
	{
		camera_x = 2.0 * (double)px.x / w - 1.0;
		c->player.raydir.x = c->player.dir.x + c->player.plane.x * camera_x;
		c->player.raydir.y = c->player.dir.y + c->player.plane.y * camera_x;
		init_dda(c,
			draw_make_px((int)c->player.pos.x, (int)c->player.pos.y), &ray);
		if (ray.dist <= 0.0)
			return ;
		ray.h = abs((int)((double)c->x->height / ray.dist));
		display_vertical(c, &ray, px.x);
		px.x++;
	}
}
