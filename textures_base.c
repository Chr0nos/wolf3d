/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/31 15:12:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

#define TEXTURES_COUNT 9

static int		texture_error(const char *path)
{
	ft_printf("error while loading texture: %s : failed to open file\n", path);
	return (-2);
}

int				textures_load(t_context *c)
{
	const char		*txpath[] = { "./textures/box.xpm",
		"./textures/gun.xpm", "./textures/zaz.xpm", "./textures/walljap.xpm",
	"./textures/walljapneko.xpm", "./textures/bones.xpm",
	"./textures/qubi.xpm", "./textures/girl.xpm", "./textures/sol.xpm"};
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
		if (!(tex->img = mlx_xpm_file_to_image(c->x->mlxptr, txpath[p],
			&tex->width, &tex->height)))
			return (texture_error(txpath[p]));
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

	if ((!c->map.tex) || (c->x->mlxptr))
		return ;
	p = TEXTURES_COUNT;
	while ((p--) && (c->map.tex[p].img))
		mlx_destroy_image(c->x->mlxptr, c->map.tex[p].img);
	free(c->map.tex);
	c->map.tex = 0;
}
