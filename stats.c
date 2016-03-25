/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:27:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 02:03:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "mlx.h"
#include "libft.h"

void	display_stats(t_context *c)
{
	char	buffer[128];
	char	tmp[12];
	static int	count = 0;

	ft_itobuff(tmp, (int)c->player.pos.x, 10, "0123456789");
	ft_strcpy(buffer, "player: x: ");
	ft_strcat(buffer, tmp);
	ft_itobuff(tmp, (int)c->player.pos.y, 10, "0123456789");
	ft_strcat(buffer, " y:");
	ft_strcat(buffer, tmp);
	ft_strcat(buffer, " count: ");
	ft_itobuff(tmp, count++, 10, "0123456789");
	ft_strcat(buffer, tmp);
	mlx_string_put(c->x->mlxptr, c->x->winptr, 5, 5, COLOR_WHITE, buffer);
}
