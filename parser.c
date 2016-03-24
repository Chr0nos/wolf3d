/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:05:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 15:38:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		load_map(t_context *c, t_list *lst, unsigned int lines_count)
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

int				parser(const char *mpath, t_context *c)
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
	{
		ft_lstadd(&lst, ft_lstnewlink(line, ft_strlen(line)));
		lc++;
	}
	close(fd);
	fd = load_map(c, lst, lc);
	if (fd > 0)
	{
		fd = popper(c);
	}
	ft_lstdel(&lst, NULL);
	return (fd);
}
