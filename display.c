/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 18:06:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>

int				display(t_context *c)
{
	draw_reset_image(c->x, 0x00000000);
	init_display(c);
	draw_flush_image(c->x, c->x->img);
	display_stats(c);
	return (0);
}

static void		*display_loop(t_context *c)
{
	while (display(c) == 0)
		usleep(100);
	return (c);
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
	y[2] = (ray->side == 0) ? COLOR_CYAN : COLOR_GREEN;
	wall = draw_make_line(x, y[0], x, y[1]);
	if ((ray->obstacle == -1) && (c->flags & FLAG_HIDE_OUTERWALLS))
	{
		wall = draw_make_line(x, c->x->height / 2, x, c->x->height / 2);
		y[2] = COLOR_BROWN;
	}
	sky = draw_make_line(x, 0, x, wall.start.y);
	sol = draw_make_line(x, wall.end.y, x, c->x->height);
	draw_line(c->x, &sky, COLOR_BLUE);
	draw_line(c->x, &sol, COLOR_BROWN);
	draw_line(c->x, &wall, y[2]);
}

void			display_loop_start(t_context *c)
{
	pthread_create(&c->map.thread, NULL, (void*(*)(void*))&display_loop, c);
}
