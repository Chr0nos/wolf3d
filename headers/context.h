/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:30:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/22 18:18:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include <string.h>
# include "draw.h"
# include "textures.h"

typedef char		t_mode;

typedef struct		s_posxy
{
	double			x;
	double			y;
}					t_posxy;

typedef struct		s_ray
{
	double			camera_x;
	double			dist;
	double			h;
	double			wallx;
	t_posxy			pos;
	t_posxy			dir;
	t_posxy			deltadis;
	t_posxy			sidedist;
	t_posxy			step;
	int				side;
	int				obstacle;
	int				orientation;
	int				padding;
}					t_ray;

typedef struct		s_buffer
{
	char			*data;
	int				size;
	int				padding;
}					t_buffer;

typedef struct		s_player
{
	t_posxy			rootpos;
	t_posxy			pos;
	t_posxy			plane;
	t_posxy			raydir;
	t_posxy			dir;
	double			speed;
}					t_player;

typedef struct		s_map
{
	t_buffer		*b;
	t_texture		*tex;
	unsigned int	lines;
	int				flags;
	int				img_count;
	unsigned int	colors[8][4];
	int				padding;
	char			path[256];
}					t_map;

typedef struct		s_context
{
	t_draw			d;
	t_map			map;
	t_player		player;
	size_t			keyboard;
	size_t			flags;
}					t_context;

typedef struct		s_display_swf
{
	t_line			sky;
	t_line			wall;
	t_line			sol;
}					t_swf;

#endif
