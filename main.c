/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 16:42:24 by snicolet         ###   ########.fr       */
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
	c->player.posx = 5.0f;
	c->player.posy = 3.0f;
	c->player.fov = 60;
	c->player.dir.x = -1.0f;
	c->player.dir.y = 0.0f;
	c->player.dir.z = 0.0f;
	c->map.xtime = 0;
	c->map.ltime = 0;
}
#include "mlx.h"
int				main(void)
{
	t_context	c;

	if (!(c.x = draw_init("Wolf 3d", SIZE_X, SIZE_Y)))
		ft_putendl("error: unable to initialise mlx window");
	else if (parser("./maps/base.map", &c) < 0)
		ft_putendl("error: unable to load the file for some reason.");
	else
	{
		set_defaults(&c);
		display_map(&c);
		//display_loop_start(&c);
		set_hooks(&c);
		//display(&c);
		//draw_loop(c.x);
		draw_loop_hook(c.x, &display, &c);
		//mlx_loop_hook(c.x->mlxptr, &display, &c);
	}
	return (0);
}
