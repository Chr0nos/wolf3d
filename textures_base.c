/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 20:08:23 by snicolet         ###   ########.fr       */
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
		"./textures/gun.xpm", "./textures/zaz.xpm", "./textures/walljap.xpm",
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
			return (texture_error(txpath[p]));
		//SDL_LockSurface(tex->surface);
		//SDL_UnlockSurface(tex->surface);
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
	while ((p--) && (c->map.tex[p].surface))
		SDL_FreeSurface(c->map.tex[p].surface);
	free(c->map.tex);
	c->map.tex = 0;
}
