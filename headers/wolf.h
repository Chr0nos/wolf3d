/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/21 13:16:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define SIZE_X 1024
# define SIZE_Y 768
# define MAP_MAX_SIZE 10000
# include "draw.h"
# ifdef __APPLE__
#  include "keycodes_mac.h"
# else
#  include "keycodes_linux.h"
# endif

typedef struct		s_buffer
{
	char			*data;
	int				size;
	int				padding;
}					t_buffer;

typedef struct		s_player
{
	int				x;
	int				y;
}					t_player;

typedef struct		s_map
{
	t_buffer		*b;
	unsigned int	lines;
	int				padding;
}					t_map;

typedef struct		s_context
{
	t_mlx			*x;
	t_map			map;
	t_player		player;
}					t_context;

void				display(t_context *c);
void				display_map(t_context *c);
int					closer(t_context *c);
int					keydown(int keycode, t_context *c);
int					mouse_move(int x, int y, t_context *c);
int					parser(const char *mpath, t_context *c);

#endif
