/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:50:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 16:21:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <unistd.h>

void	display_map(t_context *c)
{
	unsigned int		p;

	ft_putendl("map:");
	p = 0;
	while (p < c->map.lines)
	{
		ft_printf("[%d]: ", p);
		write(1, c->map.b[p].data, (unsigned int)c->map.b[p].size);
		write(1, "\n", 1);
		p++;
	}
	ft_putendl("map end.");
}

void	display_map_walk(t_context *c)
{
	t_point		px;

	px.y = 0;
	while ((unsigned int)px.y < c->map.lines)
	{
		px.x = 0;
		while (px.x < c->map.b[px.y].size)
		{
			write(1, (c->map.b[px.y].data[px.x] == '0') ? "0" : "1", 1);
			px.x++;
		}
		write(1, "\n", 1);
		px.y++;
	}
}
