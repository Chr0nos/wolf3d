/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:07:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/31 02:45:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		dtf_init(t_context *c, const t_ray *ray, t_posxy *fl)
{
	const t_posxy	*map = &c->player.pos;

	if (ray->orientation == PO_N)
	{
		fl->x = map->x;
		fl->y = map->y + ray->wallx;
	}
	else if (ray->orientation == PO_S)
	{
		fl->x = map->x + 1.0;
		fl->y = map->y + ray->wallx;
	}
	else if (ray->orientation == PO_E)
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
	double			dist_player;

(void)tex;
	dist_player = 0.0;
	dtf_init(c, ray, &fl);
	px = wall->end;
	while (px.y < c->x->height)
	{
		current_dist = h / (2.0 * px.y - h);
		coefw = (current_dist - ray->dist) / (ray->dist - dist_player);
		cfl.x = coefw * fl.x + (1.0 - coefw) * c->player.rootpos.x;
		cfl.y = coefw * fl.y + (1.0 - coefw) * c->player.rootpos.y;
		draw_px(c->x, &px, texture_px(tex, draw_make_px(
			(int)(cfl.x * tex->width) % tex->width,
			(int)(cfl.y * tex->height) % tex->height
		)));
		//draw_px(c->x, &px, COLOR_BROWN);
		px.y++;
	}
}
