/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 14:27:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"

static void		set_hooks(t_context *c)
{
	draw_sethook_ng(c->x, &closer, c, CLOSE);
	draw_sethook_ng(c->x, &keydown, c, KEYDOWN);
	draw_sethook_ng(c->x, &keyrlz, c, KEYUP);
	draw_sethook_ng(c->x, &mouse_move, c, MOUSEMOVE);
}

static void		colors_set(t_context *c)
{
	c->map.colors[0] = draw_make_px(0x000d5925, 0x00097100);
	c->map.colors[1] = draw_make_px(0x000d5925, 0x00097100);
	c->map.colors[2] = draw_make_px(COLOR_RED, 0x00a2130a);
	c->map.colors[3] = draw_make_px(0x00233e4a, 0x00101d2f);
	c->map.colors[4] = c->map.colors[0];
}

void			set_defaults(t_context *c)
{
	c->map.img_count = 0;
	c->player.pos = c->player.rootpos;
	c->player.dir.x = 1.0;
	c->player.dir.y = 0.0;
	c->player.speed = 0.12;
	c->player.plane.x = 0.0;
	c->player.plane.y = 0.66;
	c->flags = FLAG_NONE;
	colors_set(c);
}

int				main(int ac, char **av)
{
	t_context	c;

	if ((ac != 2) || (!ft_strlen(av[1])))
		ft_printf("usage: %s <filepath>\n", av[0]);
	else if (parser(av[1], &c) < 0)
	{
		ft_putendl("error: unable to load the file for some reason.");
		clean_map(&c);
	}
	else if (!(c.x = draw_init("Wolf 3d", SIZE_X, SIZE_Y)))
		ft_putendl("error: unable to initialise mlx window");
	else
	{
		c.keyboard = 0;
		set_defaults(&c);
		display_map(&c);
		set_hooks(&c);
		draw_loop_hook(c.x, &display, &c);
		draw_loop(c.x);
		ft_putendl("quitting");
	}
	return (0);
}
