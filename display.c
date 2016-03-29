/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/29 10:17:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>
#include "mlx.h"
#include <math.h>

int				display(t_context *c)
{
	move_myass(c, c->keyboard);
	init_display(c);
	//texture_push(c, &c->map.tex[0], draw_make_px(42, 10));
	draw_flush_image(c->x, c->x->img);
	display_stats(c);
	mlx_put_image_to_window(c->x->mlxptr, c->x->winptr,
		c->map.tex[1].img, 150,
		c->x->height - c->map.tex[1].height);
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

static int		get_orientation(const t_ray *ray)
{
	if (ray->side == 0)
		return ((ray->step.x == 1.0) ? PO_N : PO_S);
	else if (ray->side == 1)
		return ((ray->step.y == 1.0) ? PO_E : PO_W);
	return (PO_ERROR);
}

static void		display_vertical_tex(t_context *c, t_ray *ray, t_line *line)
{
	const double	h = (double)c->x->height;
	t_point			px;
	t_point			tpx;
	t_texture		*tex;
	int				wallx;

	tex = &c->map.tex[0];
	if (ray->side == 1)
		wallx = (int)(ray->pos.x + ((double)line->start.y - ray->pos.y + (1.0 - ray->step.y) / 2.0 / ray->dir.y) * ray->dir.x);
	else
		wallx = (int)(ray->pos.y + ((double)line->start.x - ray->pos.x + (1.0 - ray->step.x) / 2.0 / ray->dir.x) * ray->dir.y);
	wallx -= wallx;
	tpx.x = wallx * tex->width;
	if (((ray->side == 0) && (ray->dir.x > 0)) ||
	((ray->side == 1) && (ray->dir.y < 0)))
		tpx.x = tex->width - tpx.x - 1;
	px = line->start;
	while (px.y < line->end.y)
	{
		tpx.y = (int)(((double)(px.y * 2) - h + ray->h) *
			(((double)tex->height / 2.0) / ray->h));
		tpx.y = ft_abs(tpx.y);
		draw_px(c->x, &px, texture_px(tex, tpx));
		px.y++;
	}
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
	int				y[4];

	y[0] = fix_y((int)(-ray->h / 2.0 + h / 2.0), c->x->height);
	y[1] = fix_y((int)(ray->h / 2.0 + h / 2.0), c->x->height);
	y[3] = get_orientation(ray);
	if ((ray->obstacle < 0) || (ray->obstacle > COLORS_COUNT))
		y[2] = c->map.colors[0][y[3]];
	else
		y[2] = c->map.colors[ray->obstacle][y[3]];
	if ((ray->obstacle == 4) && (c->flags & FLAG_HIDE_OUTERWALLS))
	{
		wall = draw_make_line(x, c->x->height / 2, x, c->x->height / 2);
		y[2] = COLOR_BROWN;
	}
	else
		wall = draw_make_line(x, y[0], x, y[1]);
	//y[2] = color_fog(y[2], 1.0);
	sky = draw_make_line(x, 0, x, wall.start.y);
	sol = draw_make_line(x, wall.end.y, x, c->x->height);
	draw_line(c->x, &sky, 0x005decff);
	draw_line(c->x, &sol, COLOR_BROWN);
	if (!(c->flags & FLAG_TEXTURES))
		draw_line(c->x, &wall, y[2]);
	else
		display_vertical_tex(c, ray, &wall);
}
