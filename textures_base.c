/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/24 21:31:50 by snicolet         ###   ########.fr       */
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
	const char		*txpath[] = { "./jpg/box.jpg", "./textures/gun.xpm",
	"./textures/zaz.xpm", "./textures/wall.jpg", "./jpg/neko2.png",
	"./jpg/bones.png", "./jpg/qubi.jpg", "./jpg/girl.png",
	"./textures/wall2.jpg"};
	unsigned int	p;

	if (!(c->map.tex = malloc(sizeof(t_texture) * TEXTURES_COUNT)))
		return (-1);
	p = 0;
	while (p < TEXTURES_COUNT)
	{
		texture_loadid((const char**)txpath, p, &c->map.tex[p], c);
		p++;
	}
	ft_putendl("textures done.");
	return (1);
}

int		texture_loadid(const char **txpath, unsigned int p, t_texture *tex,
	t_context *c)
{
	ft_printf("loading texture: %s\n", txpath[p]);
	if (!(tex->surface = IMG_Load(txpath[p])))
	{
		texture_error(txpath[p]);
		if (!(tex->surface = SDL_CreateRGBSurface(0, 1, 1, 32, 0x00ff0000,
			0x0000ff00, 0x000000ff, 0xff000000)))
			return (-2);
		draw_reset_surface(tex->surface, COLOR_CYAN);
	}
	texture_loadsurface(c, txpath, p);
	tex->id = p;
	return (0);
}

int		texture_loadsurface(t_context *c, const char **txpath, int p)
{
	t_texture		*tex;
	size_t			size;

	tex = &c->map.tex[p];
	tex->tex = SDL_CreateTexture(c->d.render, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, tex->surface->w, tex->surface->h);
	if (!tex->tex)
		return (texture_error(txpath[p]));
	if (SDL_LockTexture(tex->tex, NULL, (void*)&tex->pixels, &tex->pitch) == 0)
	{
		size = tex->pitch * tex->surface->h;
		draw_pixelsconvert(tex->pixels, tex->surface->pixels,
				tex->surface->format->BytesPerPixel, size / 4);
		texture_convertformat(tex);
	}
	else
		ft_printf("sdl error (lock): %s\n", SDL_GetError());
	return (0);
}

void			textures_clean(t_context *c)
{
	unsigned int	p;

	if (!c->map.tex)
		return ;
	p = TEXTURES_COUNT;
	while (p--)
	{
		if (c->map.tex[p].surface)
		{
			SDL_FreeSurface(c->map.tex[p].surface);
			SDL_DestroyTexture(c->map.tex[p].tex);
			c->map.tex[p].surface = NULL;
		}
	}
	free(c->map.tex);
	c->map.tex = 0;
}
