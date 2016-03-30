/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:50:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 16:29:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>
#include "mlx.h"
#include "draw.h"
#include "libft.h"
#define TEXTURES_COUNT 4

int				textures_load(t_context *c)
{
	const char		*txpath[] = { "./textures/sol.xpm",
		"./textures/gun2.xpm", "./textures/zaz.xpm", "./textures/walljap.xpm"};
	unsigned int	p;
	int				e;
	t_texture		*tex;

	if (!(c->map.tex = malloc(sizeof(t_texture) * TEXTURES_COUNT)))
		return (-1);
	p = 0;
	while (p < TEXTURES_COUNT)
	{
		ft_printf("loading texture: %s\n", txpath[p]);
		tex = &c->map.tex[p];
		tex->img = mlx_xpm_file_to_image(c->x->mlxptr, txpath[p],
			&tex->width, &tex->height);
		tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &e);
		p++;
	}
	ft_putendl("textures done.");
	return (1);
}

void			textures_clean(t_context *c)
{
	unsigned int	p;

	if (!c->map.tex)
		return ;
	p = TEXTURES_COUNT;
	while (p--)
		mlx_destroy_image(c->x->mlxptr, c->map.tex[p].img);
	free(c->map.tex);
	c->map.tex = 0;
}

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
