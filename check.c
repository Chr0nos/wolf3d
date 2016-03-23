/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:36:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/23 18:33:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		check_obstacle(t_context *c, int x, int y)
{
	if ((y <= 0) || (c->map.lines < (unsigned int)y))
		return (1);
	else if ((x <= 0) || (c->map.b[y].size < x))
		return (1);
	else if (c->map.b[y].data[x] == 0)
		return (0);
	return ((int)c->map.b[y].data[x] - '0');
}
