/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/24 19:06:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define SIZE_X 1920
# define SIZE_Y 1080
# define MAP_MAX_SIZE 10000
# include "draw.h"
# include "keycodes.h"
# include "flags.h"
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
	int				obstacle;
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
	size_t			flags;
}					t_context;

void				clean_map(t_context *c);
void				set_defaults(t_context *c);
void				player_forward(t_context *c, double speed);
void				player_rotate(t_context *c, double rotate_speed);
void				player_crab(t_context *c, double speed);
void				init_display(t_context *c);
void				display_map(t_context *c);
void				display_map_walk(t_context *c);
void				display_loop_start(t_context *c);
void				display_stats(t_context *c);
void				display_vertical(t_context *c, t_ray *ray, const int x);
int					display(t_context *c);
int					closer(t_context *c);
int					popper(t_context *c);
int					keydown(int keycode, t_context *c);
int					keyrlz(int keycode, t_context *c);
int					mouse_move(int x, int y, t_context *c);
int					parser(const char *mpath, t_context *c);
int					check_obstacle(t_context *c, int x, int y);
int					move_myass(t_context *c);

#endif
