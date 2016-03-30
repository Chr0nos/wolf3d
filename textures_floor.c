/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 21:07:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 21:18:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		dtf_init(t_context *c, const t_ray *ray, t_posxy *fl)
{
	t_point		map;

	map.x = (int)c->player.pos.x;
	map.y = (int)c->player.pos.y;
	if (ray->orientation == PO_N)
	{
		fl->x = map.x;
		fl->y = map.y + ray->wallx;
	}
	else if (ray->orientation == PO_S)
	{
		fl->x = map.x + 1.0;
		fl->y = map.y + ray->wallx;
	}
	else if (ray->orientation == PO_E)
	{
		fl->x = map.x + ray->wallx;
		fl->y = map.y;
	}
	else {
		fl->x = map.x + ray->wallx;
		fl->y = map.y + 1.0;
	}
}

void	display_tex_floor(t_context *c, const t_ray *ray, const t_line *wall)
{
	t_posxy		fl;
	t_point		px;

	dtf_init(c, ray, &fl);
	px = wall->end;
	while (px.y < c->x->height)
	{
		draw_px(c->x, &px, COLOR_BROWN);
		px.y++;
	}
}
