/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 18:24:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

static int		key_move(int keycode, t_context *c)
{
	if (keycode == KEY_W)
		player_forward(c, -c->player.speed);
	else if (keycode == KEY_S)
		player_forward(c, c->player.speed);
	else if (keycode == KEY_D)
		player_crab(c, c->player.speed);
	else if (keycode == KEY_A)
		player_crab(c, -c->player.speed);
	else
		return (0);
	return (1);
}

int				keyrlz(int keycode, t_context *c)
{
	(void)keycode;
	(void)c;
	return (0);
}

int				keydown(int keycode, t_context *c)
{
	if (keycode == KEY_ESC)
		return (closer(c));
	else if (key_move(keycode, c))
		;
	else if (keycode == KEY_R)
		set_defaults(c);
	else if (keycode == KEY_LEFT)
		player_rotate(c, -0.3);
	else if (keycode == KEY_RIGHT)
		player_rotate(c, 0.3);
	else if (keycode == KEY_N)
		c->flags ^= FLAG_HIDE_OUTERWALLS;
	else
	{
		ft_printf("unknow key code: %d\n", keycode);
		return (0);
	}
	if (c->flags & FLAG_DEBUG)
		display(c);
	return (0);
}

int				mouse_move(int x, int y, t_context *c)
{
	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	return (0);
}
