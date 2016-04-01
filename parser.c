/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:05:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/01 01:44:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

static unsigned int	parser_load(t_context *c, t_list **lst, char *line)
{
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
	int				ret;
	char			*line;
	t_list			*lst;
	unsigned int	lc;

	if (!(fd = open(mpath, O_RDONLY)))
		return (-1);
	lst = 0;
	lc = 0;
	while ((ret = ft_get_next_line(fd, &line) > 0))
		lc += parser_load(c, &lst, line);
	close(fd);
	fd = load_map(c, lst, lc);
	if (fd > 0)
	{
		fd = popper(c);
		if (fd < 0)
			ft_putendl("map error: unable to find a suitable spawn point");
	}
	ft_lstdel(&lst, NULL);
	return (fd);
}
