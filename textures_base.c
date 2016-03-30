/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 18:25:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

#define TEXTURES_COUNT 5

int				textures_load(t_context *c)
{
	const char		*txpath[] = { "./textures/sol.xpm",
		"./textures/gun2.xpm", "./textures/zaz.xpm", "./textures/walljap.xpm",
	"./textures/walljapneko.xpm"};
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
		tex->id = p;
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
