/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/26 01:35:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>

int				display(t_context *c)
{
	move_myass(c, c->keyboard);
	init_display(c);
	draw_flush_image(c->x, c->x->img);
	display_stats(c);
	return (0);
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
** y[2] contains the color of the wall: DO NOT ask why...
*/

void			display_vertical(t_context *c, t_ray *ray, const int x)
{
	const double	h = (double)c->x->height;
	t_line			wall;
	t_line			sky;
	t_line			sol;
	int				y[3];

	y[0] = fix_y((int)(-ray->h / 2.0 + h / 2.0), c->x->height);
	y[1] = fix_y((int)(ray->h / 2.0 + h / 2.0), c->x->height);

	if ((ray->obstacle < 0) || (ray->obstacle > COLORS_COUNT))
		y[2] = (ray->side == 0) ? c->map.colors[0].x : c->map.colors[0].y;
	else
		y[2] = (ray->side) ? c->map.colors[ray->obstacle].x : \
		c->map.colors[ray->obstacle].y;
	if ((ray->obstacle == 4) && (c->flags & FLAG_HIDE_OUTERWALLS))
	{
		wall = draw_make_line(x, c->x->height / 2, x, c->x->height / 2);
		y[2] = COLOR_BROWN;
	}
	else
		wall = draw_make_line(x, y[0], x, y[1]);
	sky = draw_make_line(x, 0, x, wall.start.y);
	sol = draw_make_line(x, wall.end.y, x, c->x->height);
	draw_line(c->x, &sky, 0x005decff);
	draw_line(c->x, &sol, COLOR_BROWN);
	draw_line(c->x, &wall, y[2]);
}
