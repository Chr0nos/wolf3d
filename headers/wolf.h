/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/28 20:50:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define SIZE_X 1024
# define SIZE_Y 768
# define COLORS_COUNT 5
# include "draw.h"
# include "keycodes.h"
# include "flags.h"
# include "textures.h"
# include "context.h"
# include <string.h>

void	clean_map(t_context *c);
void	set_defaults(t_context *c);
void	player_forward(t_context *c, double speed);
void	player_rotate(t_context *c, double rotate_speed);
void	player_crab(t_context *c, double speed);
void	init_display(t_context *c);
void	display_map(t_context *c);
void	display_map_walk(t_context *c);
void	display_stats(t_context *c);
void	display_vertical(t_context *c, t_ray *ray, const int x);
int		display(t_context *c);
int		closer(t_context *c);
int		popper(t_context *c);
int		keydown(int keycode, t_context *c);
int		keyrlz(int keycode, t_context *c);
int		mouse_move(int x, int y, t_context *c);
int		parser(const char *mpath, t_context *c);
int		check_obstacle(t_context *c, int x, int y, t_mode mode);
int		move_myass(t_context *c, const size_t kb);
int		color_fog(int color, double fog);
int		textures_load(t_context *c);
int		texture_px(t_texture *tex, t_point px);
void	textures_clean(t_context *c);
void	colors_set(t_context *c);

#endif
