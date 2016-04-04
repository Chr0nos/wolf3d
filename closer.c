/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:25:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 03:30:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"
#include <stdlib.h>

void			clean_map(t_context *c)
{
	unsigned int	p;

	ft_putendl("cleaning map lines");
	p = c->map.lines;
	while (p--)
		free(c->map.b[p].data);
	ft_putendl("cleaning map global");
	free(c->map.b);
}

int				closer(t_context *c)
{
	//draw_clear(c->x);
	//textures_clean(c);
	clean_map(c);
	ft_putendl("cleaning SDL");
	if (c->d.win)
	{
		ft_putendl("deleting window");
		SDL_DestroyWindow(c->d.win);
	}
	SDL_Quit();
	ft_putendl("cleans done");
	return (1);
}
