/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:50:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/26 19:06:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"

unsigned int	texture_px(const t_texture *tex, t_v2i px)
{
	const unsigned int	*pixels = tex->pixels;

	return (pixels[px.y * tex->surface->w + px.x]);
}

unsigned int	texture_id(t_context *c, const t_ray *ray)
{
	const int	o = ray->obstacle;

	if (o == MAP_WALL_STD)
		return (TEX_WALLSTD);
	else if (o == MAP_ZAZ)
		return ((ray->orientation == PO_W) ? TEX_WALL2 : TEX_ZAZ);
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
