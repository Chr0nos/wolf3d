/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/20 00:16:48 by snicolet         ###   ########.fr       */
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

typedef struct	s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct	s_context
{
	t_mlx		*x;
	char		map[MAP_MAX_SIZE];
	t_player	player;
}				t_context;

int				closer(t_context *c);
int				keydown(int keycode, t_context *c);
int				parser(const char *mpath, t_context *c);

#endif
