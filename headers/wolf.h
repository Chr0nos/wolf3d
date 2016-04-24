/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:00:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/24 14:53:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define SIZE_X 1024
# define SIZE_Y 768
# define COLORS_COUNT 5
# include "draw.h"
# include "flags.h"
# include "textures.h"
# include "context.h"
# include <string.h>

void			clean_map(t_context *c);
void			set_defaults(t_context *c);
void			player_forward(t_context *c, double speed);
void			player_rotate(t_context *c, double rotate_speed);
void			player_crab(t_context *c, double speed);
void			init_display(t_context *c);
void			display_map(t_context *c);
void			display_map_walk(t_context *c);
void			display_stats(t_context *c);
void			display_vertical(t_context *c, t_ray *ray, const int x);
void			display_tex_floor(t_context *c, const t_ray *ray,
	const t_line *wall, const t_texture *tex);
int				display(t_context *c);
int				closer(t_context *c);
int				popper(t_context *c);
int				keydown(int keycode, t_context *c);
int				keyrlz(int keycode, t_context *c);
int				parser(const char *mpath, t_context *c);
int				check_obstacle(t_context *c, int x, int y, t_mode mode);
int				move_myass(t_context *c, const size_t kb);
unsigned int	color_fog(unsigned int color, double fog);
int				fix_y(int y, int maxy);
void			colors_set(t_context *c);
unsigned int	texture_id(t_context *c, const t_ray *ray);
int				sdl_event(SDL_Event *event, t_context *c);
void			event_togglefs(t_context *c);
unsigned int	color_convert(unsigned int color);
int				textures_load(t_context *c);
unsigned int	texture_px(const t_texture *tex, t_point px);
void			textures_clean(t_context *c);
void			texture_push(t_context *c, t_texture *tex,
   const t_point offset, unsigned int alpha);
int				texture_loadsurface(t_context *c, const char **txpath, int p);
void			texture_convertformat(t_texture *tex);
int				texture_loadid(const char **txpath, unsigned int p,
	t_texture *tex, t_context *c);

#endif
