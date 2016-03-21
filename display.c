/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 16:37:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>

static void		load_square(t_point *p, int size, t_point offsets)
{
	int		i;

	p[0] = draw_make_px(-size, -size);
	p[1] = draw_make_px(size, -size);
	p[2] = draw_make_px(size, size);
	p[3] = draw_make_px(-size, size);
	i = 4;
	while (i--)
	{
		p[i].x += offsets.x;
		p[i].y += offsets.y;
	}
}

int			display(t_context *c)
{
	t_point		p[4];
	int			z;

	draw_reset_image(c->x, 0x00000000);
	z = 8;
	while (z--)
	{
		load_square(p, 30 * z, draw_make_px(400, 400));
		draw_perimeter(c->x, p, 4, COLOR_GREEN);
	}
	ft_putendl("flush");
	draw_flush_image(c->x, c->x->img);
	ft_putendl("done");
	return (0);
}

static void		*display_loop(t_context *c)
{
	while (display(c) == 0)
		usleep(100);
	return (c);
}

void			display_loop_start(t_context *c)
{
	pthread_create(&c->map.thread, NULL, (void*(*)(void*))&display_loop, c);
}
