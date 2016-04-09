/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_togglefs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 23:59:18 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/09 12:15:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

void	event_togglefs(t_context *c)
{
	SDL_SetWindowFullscreen(c->d.win, (c->flags & FLAG_FULLSCREEN) ? \
	~SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_FULLSCREEN_DESKTOP);
	c->d.geometry = draw_getgeometry(c->d.win);
	c->flags ^= FLAG_FULLSCREEN;
	if (!(c->d.screen = SDL_GetWindowSurface(c->d.win)))
	{
		ft_printf("sdl error: %s\n", SDL_GetError());
	}
}
