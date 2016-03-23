/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 21:49:22 by snicolet         ###   ########.fr       */
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

static void		set_defaults(t_context *c)
{
	c->player.pos.x = 4.0f;
	c->player.pos.y = 5.0f;
	c->map.b[(int)c->player.pos.y].data[(int)c->player.pos.x] = 'x';
	c->player.plane.x = 0.66f;
	c->player.plane.y = 0.0f;
	c->player.fov = 60;
	c->player.dir.x = 0.0f;
	c->player.dir.y = 1.0f;
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
