/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:50:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/28 20:17:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>
#include "mlx.h"
#include "draw.h"
#include "libft.h"
#define TEXTURES_COUNT 2

int		textures_load(t_context *c)
{
	const char		*txpath[] = { "./textures/zaz.xpm",
		"./textures/gun2.xpm"};
	unsigned int	p;

	if (!(c->map.tex = malloc(sizeof(t_texture) * TEXTURES_COUNT)))
		return (-1);
	p = 0;
	while (p < TEXTURES_COUNT)
	{
		ft_printf("loading texture: %s\n", txpath[p]);
		c->map.tex[p].img = mlx_xpm_file_to_image(c->x->mlxptr, txpath[p],
			&c->map.tex[p].width, &c->map.tex[p].height);
		p++;
	}
	ft_putendl("textures done.");
	return (1);
}

void	textures_clean(t_context *c)
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

int		texture_px(t_texture *tex, t_point px)
{
	return (*(int *)(unsigned long)tex->img + (tex->width * px.y) +
		(px.x * 4));
}
