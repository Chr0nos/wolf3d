/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:50:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 20:54:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"

unsigned int	texture_px(t_texture *tex, t_point px)
{
	return (*(unsigned int *)((unsigned long)tex->data +
		(unsigned int)(tex->size_line * px.y) +
		(unsigned int)(px.x * 4)));
}

void			texture_push(t_context *c, t_texture *tex, const t_point offset,
	unsigned int alpha)
{
	t_point		px;
	t_point		real;

	px.x = tex->width;
	while (px.x--)
	{
		real.x = offset.x + px.x;
		px.y = tex->height;
		while (px.y--)
		{
			real.y = offset.y + px.y;
			draw_px(c->x, &real, ((texture_px(tex, px) & 0x00ffffff) | alpha));
		}
	}
}

unsigned int	texture_id(t_context *c, const t_ray *ray)
{
	const int	o = ray->obstacle;

	if (o == 0)
		return (3);
	else if (o == '2')
		return ((ray->orientation == PO_W) ? 0 : 2);
	else if (o == MAP_SECRET_WALL)
		return ((c->flags & FLAG_SHOWSECRETWALLS) ? 4 : 3);
	else if (o == 'b')
		return (5);
	return (3);
}
