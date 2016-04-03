/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wsdl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 12:45:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/03 21:41:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WSDL_H
# define WSDL_H
# include <SDL2/SDL.h>

typedef struct		s_wsdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Surface		*screen;
}					t_wsdl;

#endif
