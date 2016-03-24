/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 13:18:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

#include <stdio.h>

static int		key_move(int keycode, t_context *c)
{
	int		nextx;
	int		nexty;

	nextx = (int)(c->player.pos.x + c->player.dir.x * c->player.speed);
	nexty = (int)(c->player.pos.y + c->player.dir.y * c->player.speed);
	printf("next x:%d y:%d\n", nextx, nexty);
	if (keycode == KEY_W)
	{
		player_forward(c, 1.0);
	}
	else if (keycode == KEY_S)
	{
		player_forward(c, -1.0);
	}
	else if (keycode == KEY_D)
		c->player.pos.x += c->player.speed;
	else if (keycode == KEY_A)
		c->player.pos.y -= c->player.speed;
	else
		return (0);
	printf("new player pos: x:%f y:%f\n", c->player.pos.x, c->player.pos.y);
	display(c);
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
	else if (keycode == KEY_LEFT)
		player_rotate(c, 0.8);
	else if (keycode == KEY_RIGHT)
		player_rotate(c, -0.8);
	else
	{
		ft_printf("unknow key code: %d\n", keycode);
		return (0);
	}
	display(c);
	return (0);
}

int				mouse_move(int x, int y, t_context *c)
{

	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	return (0);
}
