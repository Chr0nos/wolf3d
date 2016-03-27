/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/27 12:46:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int				move_myass(t_context *c, const size_t kb)
{
	if ((kb & (KB_FORWARD | KB_UP)) && (kb & (KB_BACK | KB_DOWN)))
		;
	else if ((kb & KB_FORWARD) || (kb & KB_UP))
		player_forward(c, -c->player.speed * ((kb & KB_SHIFT) ? 1.3 : 1.0));
	else if ((kb & KB_BACK) || (kb & KB_DOWN))
		player_forward(c, c->player.speed * ((kb & KB_SHIFT) ? 1.5 : 1.0));
	if ((kb & KB_LEFT) && (kb & KB_RIGHT))
		;
	else if (kb & KB_LEFT)
		player_rotate(c, -0.045);
	else if (kb & KB_RIGHT)
		player_rotate(c, 0.045);
	if ((kb & KB_CLEFT) && (kb & KB_CRIGHT))
		;
	else if (kb & KB_CLEFT)
		player_crab(c, -c->player.speed * 0.9);
	else if (kb & KB_CRIGHT)
		player_crab(c, c->player.speed * 0.9);
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
	const int		key[] = { KEY_W, KEY_S, KEY_UP, KEY_DOWN, KEY_D, KEY_A,
		KEY_LEFT, KEY_RIGHT, KEY_SHIFT };
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
			return (1);
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
	if (keycode == KEY_ESC)
		return (closer(c));
	else if (key_move(keycode, c, EVENT_SET))
		;
	else if (keycode == KEY_R)
		set_defaults(c);
	else if (keycode == KEY_N)
		c->flags ^= FLAG_HIDE_OUTERWALLS;
	else if (keycode == KEY_I)
		c->flags ^= FLAG_SHOWINVISIBLE;
	else
	{
		ft_printf("unknow key code: %d\n", keycode);
		return (0);
	}
	return (0);
}

int				mouse_move(int x, int y, t_context *c)
{
	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	return (0);
}
