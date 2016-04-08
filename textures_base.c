/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/08 02:12:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <stdlib.h>
#include <SDL2/SDL_image.h>

#define TEXTURES_COUNT 9

static int		texture_error(const char *path)
{
	ft_printf("error while loading texture: %s : %s\n", path, IMG_GetError());
	return (-2);
}

int				textures_load(t_context *c)
{
	const char		*txpath[] = { "./jpg/box.jpg",
		"./textures/gun.xpm", "./textures/zaz.xpm", "./textures/wall.jpg",
	"./textures/walljapneko.xpm", "./textures/bones.xpm",
	"./jpg/qubi.jpg", "./textures/girl.xpm", "./textures/sol.xpm"};
	unsigned int	p;
	t_texture		*tex;

	if (!(c->map.tex = malloc(sizeof(t_texture) * TEXTURES_COUNT)))
		return (-1);
	p = 0;
	while (p < TEXTURES_COUNT)
	{
		ft_printf("loading texture: %s\n", txpath[p]);
		tex = &c->map.tex[p];
		if (!(tex->surface = IMG_Load(txpath[p])))
		{
			texture_error(txpath[p]);
			if (texture_nullifier(tex, p) < 0)
				return (-2);
		}
		tex->id = p++;
	}
	ft_putendl("textures done.");
	return (1);
}

/*
** this function is here to set all non initilized textures to a single pixel one
** and give them a valid id
*/
int			texture_nullifier(t_texture *tex, int id)
{
	tex->surface = SDL_CreateRGBSurface(0, 1, 1, 32, 0x00ff0000,
		0x0000ff00, 0x000000ff, 0xff000000);
	draw_reset_surface(tex->surface, COLOR_CYAN);
	tex->id = id;
	return (0);
}

void			textures_clean(t_context *c)
{
	unsigned int	p;

	if (!c->map.tex)
		return ;
	p = TEXTURES_COUNT;
	while ((p--) && (c->map.tex[p].surface))
		SDL_FreeSurface(c->map.tex[p].surface);
	free(c->map.tex);
	c->map.tex = 0;
}
