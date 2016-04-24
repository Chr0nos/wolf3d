/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:05:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/22 18:19:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int			parser_check_validity(const char *line)
{
	const char		valids[] = { MAP_SPAWN, MAP_ZAZ, MAP_QUBI,
		MAP_INVISIBLE_WALL, MAP_SECRET_WALL, MAP_GIRL, MAP_COMMENT,
		MAP_TELEPORT, MAP_WALL_STD, MAP_BONES, MAP_GENERATED, ' ', '0' };
	unsigned int	p;

	p = 0;
	while (line[p])
	{
		if ((line[0] != MAP_COMMENT) && (!ft_strany(line[p], valids)))
			return (0);
		p++;
	}
	return (1);
}

static int			load_map(t_context *c, t_list *lst,
	unsigned int lines_count)
{
	unsigned int	p;

	if (!(c->map.b = malloc(sizeof(t_map) * lines_count)))
		return (-1);
	p = lines_count;
	while (p--)
	{
		c->map.b[p].data = (char*)lst->content;
		c->map.b[p].size = (int)lst->content_size;
		lst = lst->next;
	}
	c->map.lines = lines_count;
	return (1);
}

static int			parse_spe(t_context *c, char *line)
{
	(void)c;
	if (line[0] == MAP_COMMENT)
	{
		free(line);
		return (1);
	}
	return (0);
}

static int			parser_load(t_context *c, t_list **lst, char *line)
{
	if (!parser_check_validity(line))
		return (-1);
	if (!parse_spe(c, line))
	{
		ft_lstadd(lst, ft_lstnewlink(line, ft_strlen(line)));
		return (1);
	}
	return (0);
}

int					parser(const char *mpath, t_context *c)
{
	int				fd;
	int				ret[2];
	char			*line;
	t_list			*lst;
	unsigned int	lc;

	if (!(fd = open(mpath, O_RDONLY)))
		return (-1);
	lst = 0;
	lc = 0;
	while (((ret[0] = ft_get_next_line(fd, &line) > 0)) &&
			((ret[1] = parser_load(c, &lst, line)) >= 0))
		lc += (unsigned int)ret[1];
	close(fd);
	fd = load_map(c, lst, lc);
	if (fd > 0)
	{
		fd = popper(c);
		if (fd < 0)
			ft_putendl("map error: unable to find a suitable spawn point");
	}
	ft_lstdel(&lst, NULL);
	ft_strcpy(c->map.path, mpath);
	return (fd);
}
