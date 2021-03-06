/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/31 17:15:30 by snicolet         ###   ########.fr       */
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
	draw_flush_image(c->x, c->x->img);
	display_stats(c);
	mlx_put_image_to_window(c->x->mlxptr, c->x->winptr,
		c->map.tex[1].img,
		(c->x->width / 2) - c->map.tex[1].width / 2,
		c->x->height - c->map.tex[1].height);
	return (0);
}

static int		texture_get_x(t_context *c, t_ray *ray, const t_texture *tex)
{
	int			tpxx;
	double		wallx;

	if (ray->side == 1)
		wallx = c->player.pos.x + (((int)ray->pos.y - c->player.pos.y + \
		(1.0 - ray->step.y) / 2.0) / ray->dir.y) * ray->dir.x;
	else
		wallx = c->player.pos.y + (((int)ray->pos.x - c->player.pos.x + \
		(1.0 - ray->step.x) / 2.0) / ray->dir.x) * ray->dir.y;
	wallx -= floor(wallx);
	tpxx = (int)(wallx * (double)tex->width);
	if ((ray->side == 0) && (ray->dir.x > 0))
		tpxx = tex->width - tpxx - 1;
	if ((ray->side == 1) && (ray->dir.y < 0))
		tpxx = tex->width - tpxx - 1;
	ray->wallx = wallx;
	return (tpxx);
}

static void		display_vertical_tex(t_context *c, t_ray *ray, t_line *line)
{
	const double	h = (double)c->x->height;
	t_point			px;
	t_point			tpx;
	t_texture		*tex;
	unsigned int	color;

	tex = &c->map.tex[texture_id(c, ray)];
	tpx.x = texture_get_x(c, ray, tex);
	px = line->start;
	while (px.y < line->end.y)
	{
		tpx.y = (int)(((double)(px.y * 2) - h + ray->h) *
			(((double)tex->height / 2.0) / ray->h));
		if (tpx.y >= 0)
		{
			color = texture_px(tex, tpx);
			if ((ray->side == 1) && (tex->id >= 2))
				color = (color >> 1) & 8355711;
			draw_px(c->x, &px, color);
		}
		px.y++;
	}
}

static void		display_swf(t_context *c, t_swf *z, t_ray *ray, unsigned int cw)
{
	draw_line(c->x, &z->sky, 0x005decff);
	if (!(c->flags & FLAG_TEXTURES))
	{
		draw_line(c->x, &z->sol, COLOR_BROWN);
		draw_line(c->x, &z->wall, cw);
	}
	else
	{
		display_tex_floor(c, ray, &z->wall, &c->map.tex[TEX_BOX]);
		display_vertical_tex(c, ray, &z->wall);
	}
}

/*
** this function actualy draw the whole vertical line from 0 to the win size
*/

void			display_vertical(t_context *c, t_ray *ray, const int x)
{
	const double	h = (double)c->x->height;
	t_swf			z;
	const int		idx = ray->obstacle - '0';
	int				y[2];
	unsigned int	colorwall;

	y[0] = fix_y((int)(-ray->h / 2.0 + h / 2.0), c->x->height);
	y[1] = fix_y((int)(ray->h / 2.0 + h / 2.0), c->x->height);
	if ((idx < 0) || (idx >= COLORS_COUNT))
		colorwall = c->map.colors[0][ray->orientation];
	else
		colorwall = c->map.colors[ray->obstacle - '0'][ray->orientation];
	if ((ray->obstacle == MAP_GENERATED) && (c->flags & FLAG_HIDE_OUTERWALLS))
	{
		z.wall = draw_make_line(x, c->x->height / 2, x, c->x->height / 2);
		colorwall = COLOR_BROWN;
	}
	else
		z.wall = draw_make_line(x, y[0], x, y[1]);
	z.sky = draw_make_line(x, 0, x, z.wall.start.y);
	z.sol = draw_make_line(x, z.wall.end.y, x, c->x->height);
	display_swf(c, &z, ray, colorwall);
}
