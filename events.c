/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:33:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/22 20:08:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

int		keydown(int keycode, t_context *c)
{
	if (keycode == KEY_ESC)
		return (closer(c));
	else
		ft_printf("unknow key code: %d\n", keycode);
	display(c);
	return (0);
}

int		mouse_move(int x, int y, t_context *c)
{
	t_point		p;

	if ((x < 0) || (y < 0) || (x >= c->x->width) || (y >= c->x->height))
		return (0);
	p = draw_make_px(x, y);
	draw_px(c->x, &p, COLOR_PURPLE);
	draw_flush_image(c->x, c->x->img);
	return (0);
}
