/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:27:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 17:28:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		fix_y(int y, int maxy)
{
	if (y < 0)
		return (0);
	if (y >= maxy)
		return (maxy - 1);
	return (y);
}
