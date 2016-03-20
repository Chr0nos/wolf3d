/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/20 13:54:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"

static void		load_square(t_point *p, int size, t_point offsets)
{
	int		i;

	p[0] = draw_make_px(0, 0);
	p[1] = draw_make_px(size, 0);
	p[2] = draw_make_px(size, size);
	p[3] = draw_make_px(0, size);
	i = 4;
	while (i--)
	{
		p[i].x += offsets.x;
		p[i].y += offsets.y;
	}
}

void	display(t_context *c)
{
	t_point		p[4];

	load_square(p, 500, draw_make_px(100, 50));
	draw_perimeter(c->x, p, 4, COLOR_GREEN);
}
