/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 15:56:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 23:18:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int		sdl_init(t_context *c, int x, int y)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("error: failed to init sdl");
		return (-1);
	}
	c->geometry = draw_make_px(x, y);
	c->d.win = SDL_CreateWindow("Wold3d",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y,
			SDL_WINDOW_RESIZABLE);
	if (!c->d.win)
	{
		ft_putendl("error: failed to init sdl window");
		return (-2);
	}
	ft_putendl("getting surface");
	c->d.screen = SDL_GetWindowSurface(c->d.win);
	if (!(c->d.screen))
		ft_printf("SDL_Init failed: %s\n", SDL_GetError());
	else
		ft_printf("screen: %p\n", c->d.screen);
	return (1);
}
