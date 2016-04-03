/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:27:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 23:21:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "mlx.h"
#include "libft.h"

void	display_stats(t_context *c)
{
	char	buffer[128];
	char	tmp[12];

	if (c->map.img_count == 2147483647)
		c->map.img_count = 0;
	ft_itobuff(tmp, (int)c->player.pos.x, 10, "0123456789");
	ft_strcpy(buffer, "player: x: ");
	ft_strcat(buffer, tmp);
	ft_itobuff(tmp, (int)c->player.pos.y, 10, "0123456789");
	ft_strcat(buffer, " y:");
	ft_strcat(buffer, tmp);
	ft_strcat(buffer, " count: ");
	ft_itobuff(tmp, c->map.img_count++, 10, "0123456789");
	ft_strcat(buffer, tmp);
}
