/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:02:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/30 17:33:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct	s_texture
{
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	unsigned int	id;
	unsigned int	padding;
	char			*img;
	char			*data;
}				t_texture;

#endif
