/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:13:07 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/28 20:51:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

static int		rgb(int r, int g, int b)
{
	return ((b & 0x000000ff) | ((g << 8) & 0x0000ff00) |
		((r << 16) & 0x00ff0000));
}

int				color_fog(int color, double fog)
{
	int		r;
	int		g;
	int		b;

	r = (int)((double)(color & 0x00ff0000) / fog);
	g = (int)((double)(color & 0x0000ff00) / fog);
	b = (int)((double)(color & 0x000000ff) / fog);
	return (rgb(r, g, b));
}

static void		color_loader(int *color, const int *c)
{
	color[PO_N] = c[PO_N];
	color[PO_S] = c[PO_S];
	color[PO_E] = c[PO_E];
	color[PO_W] = c[PO_W];
}

void			colors_set(t_context *c)
{
	color_loader(c->map.colors[0],
		(int[4]){ 0x000d5925, 0x009622d9, 0x00097100, COLOR_YELLOW });
	color_loader(c->map.colors[1],
		(int[4]){ rgb(0, 80, 50), rgb(45, 136, 45),
			rgb(17, 102, 17), rgb(0, 68, 0) });
	color_loader(c->map.colors[2],
		(int[4]){ COLOR_RED, COLOR_RED, 0x00a2130a, 0x00a2130a });
	color_loader(c->map.colors[3],
		(int[4]){ 0x00233e4a, 0x00233e4a, 0x00101d2f, 0x00101d2f });
	ft_memcpy(c->map.colors[4], c->map.colors[0], sizeof(int) * 4);
}
