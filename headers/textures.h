/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:02:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/17 11:07:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H
# include <SDL2/SDL.h>

typedef struct		s_texture
{
	SDL_Surface		*surface;
	SDL_Texture		*tex;
	unsigned int	*pixels;
	int				pitch;
	unsigned int	id;
	unsigned int	padding;
}					t_texture;

#endif
