/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:05:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/19 23:24:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int		check_invalid(char *map, int size)
{
	while (size--)
		if (!(ft_isalnum(map[size])))
			return (0);
	return (1);
}

int				parser(const char *mpath, t_context *c)
{
	int		fd;
	int		ret;

	if (!(fd = open(mpath, O_RDONLY)))
		return (-1);
	ret = (int)read(fd, c->map, MAP_MAX_SIZE);
	if (ret <= 0)
		return (-2);
	c->map[ret] = '\0';
	return (check_invalid(c->map, ret));
}
