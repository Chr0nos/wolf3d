/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 13:53:33 by snicolet         ###   ########.fr       */
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
	c->player.x = 0;
	c->player.y = 0;
}

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
		display(&c);
		set_hooks(&c);
		draw_loop(c.x);
	}
	return (0);
}
