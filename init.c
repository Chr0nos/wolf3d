/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:27:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 23:01:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

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

	hit = 0;
	while (!hit)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadis.x;
			px.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadis.y;
			px.y += ray->step.y;
			ray->side = 1;
		}
		if (check_obstacle(c, px.x, px.y))
		{
			ft_printf("obstacle found on x:%d y:%d\n", px.x, px.y);
			hit = 1;
		}
	}
	return (px);
}

static void		init_dda(t_context *c, t_point px, t_ray *ray)
{
	ray->pos = c->player.pos;
	ray->dir = c->player.raydir;
	ray->deltadis.x = sqrt(1 + pow(ray->dir.y, 2) / pow(ray->dir.x, 2));
	ray->deltadis.y = sqrt(1 + pow(ray->dir.x, 2) / pow(ray->dir.y, 2));
	init_deltas_stepdist(c, ray);
	px = init_ray(c, ray, px);
	if (ray->side == 0)
		ray->dist = fabs(((double)px.x - ray->pos.x + (1.0f - ray->step.x) / 2.0f)
		/ ray->dir.x);
	else
		ray->dist = fabs(((double)px.y - ray->pos.y + (1.0f - ray->step.y) / 2.0f)
		/ ray->dir.y);
	printf("distance: %f\n", ray->dist);
}

static void		display_vertical(t_context *c, t_line *line)
{
	t_line		sky;
	t_line		sol;

	sky = draw_make_line(line->start.x, 0, line->start.x, line->start.y);
	sol = draw_make_line(line->start.x, line->end.y, line->start.x, c->x->height);
	draw_line(c->x, &sky, COLOR_BLUE);
	draw_line(c->x, &sol, COLOR_BROWN);
}

void			init_display(t_context *c, int x)
{
	const double	w = (double)c->x->width;
	double			camera_x;
	t_line			line;
	t_point			px;
	t_ray			ray;

	px.x = x;
	while (px.x < c->x->width)
	{
		camera_x = 2.0 * (double)px.x / w - 1.0;
		c->player.raydir.x = c->player.dir.x + c->player.plane.x * camera_x;
		c->player.raydir.y = c->player.dir.y + c->player.plane.y * camera_x;
		//ft_printf("raydir: x:%d y:%d\n", (int)raydir.x, (int)raydir.y);
		px.x++;
	}
	init_dda(c, draw_make_px((int)c->player.pos.x, (int)c->player.pos.y), &ray);
	ray.h = abs((int)((double)c->x->height / ray.dist));
	line = draw_make_line(x, (int)(-ray.h / 2.0f + (double)c->x->height / 2.0f),
		x, (int)(ray.h / 2.0f + (double)c->x->height / 2.0f));
	draw_line(c->x, &line, COLOR_RED);
	display_vertical(c, &line);
}
