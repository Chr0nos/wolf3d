/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 13:53:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int				move_myass(t_context *c)
{
	if ((c->keyboard & KB_FORWARD) && (c->keyboard & KB_BACK))
		;
	else if ((c->keyboard & KB_FORWARD) || (c->keyboard & KB_UP))
		player_forward(c, -c->player.speed);
	else if ((c->keyboard & KB_BACK) || (c->keyboard & KB_DOWN))
		player_forward(c, c->player.speed);
	if ((c->keyboard & KB_LEFT) && (c->keyboard & KB_RIGHT))
		;
	else if (c->keyboard & KB_LEFT)
		player_rotate(c, -0.06);
	else if (c->keyboard & KB_RIGHT)
		player_rotate(c, 0.06);
	if ((c->keyboard & KB_CLEFT) && (c->keyboard & KB_CRIGHT))
		;
	else if (c->keyboard & KB_CLEFT)
		player_crab(c, -c->player.speed * 0.9);
	else if (c->keyboard & KB_CRIGHT)
		player_crab(c, c->player.speed * 0.9);
	else
		return (0);
	return (1);
}

static int		key_move(int keycode, t_context *c)
{
	if (keycode == KEY_W)
		c->keyboard |= KB_FORWARD;
	else if (keycode == KEY_S)
		c->keyboard |= KB_BACK;
	else if (keycode == KEY_UP)
		c->keyboard |= KB_UP;
	else if (keycode == KEY_DOWN)
		c->keyboard |= KB_DOWN;
	else if (keycode == KEY_D)
		c->keyboard |= KB_CRIGHT;
	else if (keycode == KEY_A)
		c->keyboard |= KB_CLEFT;
	else if (keycode == KEY_LEFT)
		c->keyboard |= KB_LEFT;
	else if (keycode == KEY_RIGHT)
		c->keyboard |= KB_RIGHT;
	else
		return (0);
	return (1);
}

int				keyrlz(int keycode, t_context *c)
{
	if (keycode == KEY_W)
		c->keyboard ^= KB_FORWARD;
	else if (keycode == KEY_S)
		c->keyboard ^= KB_BACK;
	else if (keycode == KEY_UP)
		c->keyboard ^= KB_UP;
	else if (keycode == KEY_DOWN)
		c->keyboard ^= KB_DOWN;
	else if (keycode == KEY_D)
		c->keyboard ^= KB_CRIGHT;
	else if (keycode == KEY_A)
		c->keyboard ^= KB_CLEFT;
	else if (keycode == KEY_LEFT)
		c->keyboard ^= KB_LEFT;
	else if (keycode == KEY_RIGHT)
		c->keyboard ^= KB_RIGHT;
	else
		return (0);
	return (1);
}

int				keydown(int keycode, t_context *c)
{
	if (keycode == KEY_ESC)
		return (closer(c));
	else if (key_move(keycode, c))
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
