/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 17:09:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>

int			display(t_context *c)
{
	int		x;

	x = 0;
	while (x < c->x->width)
	{

		x++;
	}
	init_display(c);
	draw_flush_image(c->x, c->x->img);
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
