/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:02:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/04 03:18:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H
# include <SDL2/SDL.h>

typedef struct	s_texture
{
	SDL_Surface		*surface;
	unsigned int	id;
}				t_texture;

#endif
