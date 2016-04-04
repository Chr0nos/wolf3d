/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:07:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 19:59:21 by snicolet         ###   ########.fr       */
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
	const double	h = (double)c->d.geometry.y;
	t_posxy			fl;
	t_posxy			cfl;
	t_point			px;
	double			coefw;
	double			current_dist;

	dtf_init(ray, &fl);
	px = wall->end;
	while (px.y < c->d.geometry.y)
	{
		current_dist = h / (2.0 * px.y - h);
		coefw = current_dist / ray->dist;
		if (coefw > 1.0)
			coefw = 1.0;
		cfl.x = coefw * fl.x + (1.0 - coefw) * c->player.pos.x;
		cfl.y = coefw * fl.y + (1.0 - coefw) * c->player.pos.y;
		if ((cfl.x >= 0.0) && (cfl.x < c->d.geometry.y)
		&& (cfl.y >= 0) && (cfl.y < h))
			draw_pxc(&c->d, px, draw_getpxs(tex->surface, draw_make_px(
				(int)(cfl.x * tex->surface->w) % tex->surface->w,
				(int)(cfl.y * tex->surface->h) % tex->surface->h)));
		else
			draw_pxc(&c->d, px, COLOR_BROWN);
		px.y++;
	}
}
