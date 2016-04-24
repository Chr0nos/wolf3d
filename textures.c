/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:50:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/21 13:30:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"

void			texture_push(t_context *c, t_texture *tex, const t_point offset,
	unsigned int alpha)
{
	t_point		px;
	t_point		real;

	px.x = tex->surface->w;
	while (px.x--)
	{
		real.x = offset.x + px.x;
		px.y = tex->surface->h;
		while (px.y--)
		{
			real.y = offset.y + px.y;
			draw_pxc(&c->d, real,
				((draw_getpxs(tex->surface, px) & 0x00ffffff) | alpha));
		}
	}
}

unsigned int	texture_px(const t_texture *tex, t_point px)
{
	//return (color_convert(draw_getpxs(tex->surface, px)));
	return (((unsigned int*)(tex->pixels))[tex->pitch / 4 * px.y + px.x]);
}

unsigned int	texture_id(t_context *c, const t_ray *ray)
{
	const int	o = ray->obstacle;

	if (o == MAP_WALL_STD)
		return (TEX_WALLSTD);
	else if (o == MAP_ZAZ)
		return ((ray->orientation == PO_W) ? 0 : 2);
	else if (o == MAP_QUBI)
		return (TEX_QUBI);
	else if (o == MAP_SECRET_WALL)
		return ((c->flags & FLAG_SHOWSECRETWALLS) ? 4 : 3);
	else if (o == MAP_BONES)
		return (TEX_BONES);
	else if (o == MAP_GIRL)
		return (TEX_GIRL);
	return (3);
}

void			texture_convertformat(t_texture *tex)
{
	size_t	size;

	size = tex->surface->w * tex->surface->h;
	while (size--)
		tex->pixels[size] = color_convert(tex->pixels[size]);
}
