/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 21:59:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/19 22:05:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "draw.h"
#include "libft.h"

int		main(void)
{
	t_context	c;

	if (!(c.x = draw_init("Wolf 3d", SIZE_X, SIZE_Y)))
		ft_putendl("error: unable to initialise mlx window");
	else
	{
		draw_loop(c.x);
	}
	return (0);
}
