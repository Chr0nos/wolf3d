/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:25:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 23:13:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include <stdlib.h>

void			clean_map(t_context *c)
{
	unsigned int	p;

	p = c->map.lines;
	while (p--)
		free(c->map.b[p].data);
	free(c->map.b);
}

int				closer(t_context *c)
{
	//draw_clear(c->x);
	//textures_clean(c);
	clean_map(c);
	exit(0);
}
