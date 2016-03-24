/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 14:29:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"

static void		set_hooks(t_context *c)
{
	draw_sethook_ng(c->x, &closer, c, CLOSE);
	draw_sethook_ng(c->x, &keydown, c, KEYDOWN);
	draw_sethook_ng(c->x, &mouse_move, c, MOUSEMOVE);
}

void			set_defaults(t_context *c)
{
	c->player.pos.x = 14.0;
	c->player.pos.y = 13.0;
	c->map.b[(int)c->player.pos.y].data[(int)c->player.pos.x] = 'x';
	c->player.fov = 60;
	c->player.dir.x = -1.0;
	c->player.dir.y = 0.0;
	c->player.speed = 0.3;
	c->player.plane.x = 0.0;
	c->player.plane.y = 1.0;
}

int				main(int ac, char **av)
{
	t_context	c;

	if ((ac != 2) || (!ft_strlen(av[1])))
		ft_printf("usage: %s <filepath>\n", av[0]);
	else if (parser("./maps/base.map", &c) < 0)
		ft_putendl("error: unable to load the file for some reason.");
	else if (!(c.x = draw_init("Wolf 3d", SIZE_X, SIZE_Y)))
		ft_putendl("error: unable to initialise mlx window");
	else
	{
		set_defaults(&c);
		display_map(&c);
		//display_loop_start(&c);
		set_hooks(&c);
		display(&c);
		//draw_loop_hook(c.x, &display, &c);
		draw_loop(c.x);
		ft_putendl("quitting");
	}
	return (0);
}
