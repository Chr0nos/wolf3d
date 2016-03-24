/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 15:37:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define SIZE_X 1024
# define SIZE_Y 768
# define MAP_MAX_SIZE 10000
# include "draw.h"
# include "keycodes.h"
# include <string.h>
# include <pthread.h>

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
	t_posxy			pos;
	t_posxy			dir;
	t_posxy			deltadis;
	t_posxy			sidedist;
	t_posxy			step;
	int				side;
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
	t_posxy			pos;
	t_posxy			plane;
	t_posxy			raydir;
	t_posxy			dir;
	int				fov;
	int				padding;
	double			speed;
}					t_player;

typedef struct		s_map
{
	t_buffer		*b;
	unsigned int	lines;
	int				flags;
	pthread_t		thread;
}					t_map;

typedef struct		s_context
{
	t_mlx			*x;
	t_map			map;
	t_player		player;
	size_t			keyboard;
}					t_context;

void				set_defaults(t_context *c);
void				player_forward(t_context *c, double speed);
void				player_rotate(t_context *c, double rotate_speed);
void				init_display(t_context *c);
void				display_map(t_context *c);
void				display_map_walk(t_context *c);
void				display_loop_start(t_context *c);
void				display_stats(t_context *c);
int					display(t_context *c);
int					closer(t_context *c);
int					popper(t_context *c);
int					keydown(int keycode, t_context *c);
int					mouse_move(int x, int y, t_context *c);
int					parser(const char *mpath, t_context *c);
int					check_obstacle(t_context *c, int x, int y);

#endif
