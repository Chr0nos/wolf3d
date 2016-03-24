/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:27:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 09:34:01 by snicolet         ###   ########.fr       */
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
		ray->dist = fabs(((double)px.x - ray->pos.x +
			(1.0f - ray->step.x) / 2.0f) / ray->dir.x);
	else
		ray->dist = fabs(((double)px.y - ray->pos.y +
			(1.0f - ray->step.y) / 2.0f) / ray->dir.y);
	printf("distance: %f\n", ray->dist);
}

static int		fix_y(int y, int maxy)
{
	if (y < 0)
		return (0);
	if (y >= maxy)
		return (maxy - 1);
	return (y);
}

/*
** this function actualy draw the whole vertical line from 0 to the win size
*/

static void		display_vertical(t_context *c, t_ray *ray, const int x)
{
	const double	h = (double)c->x->height;
	t_line			wall;
	t_line			sky;
	t_line			sol;
	int				y[2];

	y[0] = fix_y(abs((int)(-ray->h / 2.0f + h / 2.0f)), c->x->height);
	y[1] = fix_y(abs((int)(ray->h / 2.0f + h / 2.0f)), c->x->height);
	wall = draw_make_line(x, y[0], x, y[1]);
	sky = draw_make_line(x, 0, x, wall.start.y);
	sol = draw_make_line(x, wall.end.y, x, c->x->height);
	draw_line(c->x, &sky, COLOR_BLUE);
	draw_line(c->x, &sol, COLOR_BROWN);
	draw_line(c->x, &wall, (ray->side == 0) ? COLOR_BROWN : COLOR_GREEN);
}

void			init_display(t_context *c)
{
	const double	w = (double)c->x->width;
	double			camera_x;
	t_point			px;
	t_ray			ray;

	px.x = 0;
	while (px.x < c->x->width)
	{
		camera_x = 2.0 * (double)px.x / w - 1.0;
		c->player.raydir.x = c->player.dir.x + c->player.plane.x * camera_x;
		c->player.raydir.y = c->player.dir.y + c->player.plane.y * camera_x;
		//ft_printf("raydir: x:%d y:%d\n", (int)raydir.x, (int)raydir.y);
		init_dda(c, draw_make_px((int)c->player.pos.x, (int)c->player.pos.y), &ray);
		if (ray.dist <= 0.0f)
			return ;
		ray.h = abs((int)((double)c->x->height / ray.dist));
		display_vertical(c, &ray, px.x);
		px.x++;
	}
}
