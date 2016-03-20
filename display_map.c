/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 12:50:52 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/20 12:57:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

void	display_map(t_context *c)
{
	int		p;

	ft_putendl("map:");
	p = 0;
	while (p < c->map.lines)
	{
		ft_printf("[%d]: %s\n", p, c->map.b[p].data);
		p++;
	}
	ft_putendl("map end.");
}
