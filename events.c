/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/09 12:16:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <SDL2/SDL.h>

int				move_myass(t_context *c, const size_t kb)
{
	if (c->map.b[(int)c->player.pos.y].data[(int)c->player.pos.x]\
	== MAP_TELEPORT)
		c->player.pos = c->player.rootpos;
	if ((kb & (KB_FORWARD | KB_UP)) && (kb & (KB_BACK | KB_DOWN)))
		;
	else if ((kb & KB_FORWARD) || (kb & KB_UP))
		player_forward(c, -c->player.speed * ((kb & KB_SHIFT) ? 2.0 : 1.0));
	else if ((kb & KB_BACK) || (kb & KB_DOWN))
		player_forward(c, c->player.speed * ((kb & KB_SHIFT) ? 2.5 : 1.0));
	if ((kb & KB_LEFT) && (kb & KB_RIGHT))
		;
	else if (kb & KB_LEFT)
		player_rotate(c, -0.045);
	else if (kb & KB_RIGHT)
		player_rotate(c, 0.045);
	if ((kb & KB_CLEFT) && (kb & KB_CRIGHT))
		;
	else if (kb & KB_CLEFT)
		player_crab(c, -c->player.speed * 1.5);
	else if (kb & KB_CRIGHT)
		player_crab(c, c->player.speed * 1.5);
	else
		return (0);
	return (1);
}

/*
** this function is used by keydown and keyrlz events
** mode can be: EVENT_SET or EVENT_TOGGLE
** return 1 if the key has an event, 0 otherwhise
*/

static int		key_move(int keycode, t_context *c, int mode)
{
	const int		key[] = { SDLK_s, SDLK_w, SDLK_DOWN, SDLK_UP, SDLK_d,
		SDLK_a, SDLK_LEFT, SDLK_RIGHT, SDLK_LSHIFT };
	const size_t	kb[] = { KB_FORWARD, KB_BACK, KB_UP, KB_DOWN, KB_CRIGHT,
		KB_CLEFT, KB_LEFT, KB_RIGHT, KB_SHIFT };
	unsigned int	p;

	p = 9;
	while (p--)
	{
		if (keycode == key[p])
		{
			if (mode == EVENT_SET)
				c->keyboard |= kb[p];
			else
				c->keyboard ^= kb[p];
			return (0);
		}
	}
	return (0);
}

/*
** key release event function
*/

int				keyrlz(int keycode, t_context *c)
{
	return (key_move(keycode, c, EVENT_TOGGLE));
}

int				keydown(int keycode, t_context *c)
{
	if (keycode == SDLK_ESCAPE)
		return (1);
	else if (key_move(keycode, c, EVENT_SET))
		;
	else if (keycode == SDLK_r)
		set_defaults(c);
	else if (keycode == SDLK_n)
		c->flags ^= FLAG_HIDE_OUTERWALLS;
	else if (keycode == SDLK_i)
		c->flags ^= FLAG_SHOWINVISIBLE;
	else if (keycode == SDLK_t)
		c->flags ^= FLAG_TEXTURES;
	else if (keycode == SDLK_k)
		c->flags ^= FLAG_SHOWSECRETWALLS;
	else if (keycode == SDLK_f)
		event_togglefs(c);
	else
	{
		if (c->flags & FLAG_DEBUG_KEYS)
			ft_printf("unknow key code: %d\n", keycode);
		return (0);
	}
	return (0);
}

int				sdl_event(SDL_Event *event, t_context *c)
{
	if (event->type == SDL_QUIT)
		return (1);
	else if ((event->type == SDL_WINDOWEVENT) &&
		(event->window.event == SDL_WINDOWEVENT_RESIZED))
	{
		c->d.geometry = draw_make_px(event->window.data1, event->window.data2);
		if (!(c->d.screen = SDL_GetWindowSurface(c->d.win)))
			return (2);
	}
	else if (event->type == SDL_KEYDOWN)
		return (keydown(event->key.keysym.sym, c));
	else if (event->type == SDL_KEYUP)
		return (keyrlz(event->key.keysym.sym, c));
	return (0);
}
