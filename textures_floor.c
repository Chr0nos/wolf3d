/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:07:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/01 14:34:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		dtf_init(const t_ray *ray, t_posxy *fl)
{
	const t_posxy	*map = &ray->pos;

	if ((ray->side == 0) && (ray->dir.x > 0))
	{
		fl->x = map->x;
		fl->y = map->y + ray->wallx;
	}
	else if ((ray->side == 0) && (ray->dir.x < 0))
	{
		fl->x = map->x + 1.0;
		fl->y = map->y + ray->wallx;
	}
	else if ((ray->side == 1) && (ray->dir.y > 0))
	{
		fl->x = map->x + ray->wallx;
		fl->y = map->y;
	}
	else
	{
		fl->x = map->x + ray->wallx;
		fl->y = map->y + 1.0;
	}
}

void			display_tex_floor(t_context *c, const t_ray *ray,
	const t_line *wall, const t_texture *tex)
{
	const double	h = (double)c->x->height;
	t_posxy			fl;
	t_posxy			cfl;
	t_point			px;
	double			coefw;
	double			current_dist;

	dtf_init(ray, &fl);
	px = wall->end;
	while (px.y < c->x->height)
	{
		current_dist = h / (2.0 * px.y - h);
		coefw = current_dist / ray->dist;
		if (coefw > 1.0)
			coefw = 1.0;
		cfl.x = coefw * fl.x + (1.0 - coefw) * c->player.pos.x;
		cfl.y = coefw * fl.y + (1.0 - coefw) * c->player.pos.y;
		if ((cfl.x >= 0.0) && (cfl.x < c->x->width)
		&& (cfl.y >= 0) && (cfl.y < h))
			draw_px(c->x, &px, texture_px(tex, draw_make_px(
				(int)(cfl.x * tex->width) % tex->width,
				(int)(cfl.y * tex->height) % tex->height)));
		else
			draw_px(c->x, &px, COLOR_BROWN);
		px.y++;
	}
}
