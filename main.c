/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 02:51:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <SDL2/SDL.h>

void			set_defaults(t_context *c)
{
	c->map.img_count = 0;
	c->player.pos = c->player.rootpos;
	c->player.dir.x = 1.0;
	c->player.dir.y = 0.0;
	c->player.speed = 0.06;
	c->player.plane.x = 0.0;
	c->player.plane.y = 0.8;
	c->flags = FLAG_NONE;
	colors_set(c);
}

static int		init_wolf(t_context *c)
{
	c->map.tex = NULL;
	//if (textures_load(c) < 0)
	//	return (-1);
	c->keyboard = 0;
	set_defaults(c);
	display_map(c);
	return (1);
}

static int		sdl_loop(SDL_Event *event, t_context *c)
{
	while (SDL_PollEvent(event))
	{
		if (sdl_event(event, c))
		{
			ft_putendl("exit requested...");
			return (1);
		}
	}
	if (!(c->d.screen = SDL_GetWindowSurface(c->d.win)))
	{
		ft_printf("sdl error: %s\n", SDL_GetError());
		return (1);
	}
	display(c);
	SDL_LockSurface(c->d.screen);
	SDL_UpdateWindowSurface(c->d.win);
	SDL_UnlockSurface(c->d.screen);
	return (0);
}

int				main(int ac, char **av)
{
	int			quit;
	t_context	c;
	SDL_Event	event;

	if ((ac != 2) || (!ft_strlen(av[1])))
		ft_printf("usage: %s <filepath>\n", av[0]);
	else if (parser(av[1], &c) < 0)
	{
		ft_putendl("error: unable to load the file for some reason.");
		clean_map(&c);
	}
	else if ((draw_init(&c.d, draw_make_px(SIZE_X, SIZE_Y), "Wolf3d") > 0) && (init_wolf(&c)))
	{
		quit = 0;
		while (!sdl_loop(&event, &c))
			SDL_Delay(1);
		closer(&c);
		ft_putendl("quitting");
	}
	else
		closer(&c);
	return (0);
}
