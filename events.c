/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 23:23:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

#include <stdio.h>

static int		key_move(int keycode, t_context *c)
{
	if (keycode == KEY_W)
		c->player.pos.y -= c->player.speed;
	else if (keycode == KEY_S)
		c->player.pos.y += c->player.speed;
	else if (keycode == KEY_D)
		c->player.pos.x += c->player.speed;
	else if (keycode == KEY_A)
		c->player.pos.y -= c->player.speed;
	else
		return (0);
	printf("new player pos: x:%f y:%f\n", c->player.pos.x, c->player.pos.y);
	return (1);
}

int				keydown(int keycode, t_context *c)
{
	if (keycode == KEY_ESC)
		return (closer(c));
	else if (key_move(keycode, c))
		;
	else if (keycode == KEY_LEFT)
		c->player.raydir.x += 0.5f;
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
