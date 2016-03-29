/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:02:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/29 01:56:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct	s_texture
{
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	char		*img;
	char		*data;
}				t_texture;

#endif
