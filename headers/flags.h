/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:21:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/25 20:43:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define FLAG_NONE 0
# define FLAG_MOVE_FORWARD 1u << 1
# define FLAG_HIDE_OUTERWALLS 1u << 2
# define FLAG_SHOWINVISIBLE 1u << 3

# define KB_FORWARD 1u
# define KB_BACK 1u << 1
# define KB_LEFT 1u << 2
# define KB_RIGHT 1u << 3
# define KB_CLEFT 1u << 4
# define KB_CRIGHT 1u << 5
# define KB_UP 1u << 6
# define KB_DOWN 1u << 7
# define KB_SHIFT 1u << 8

# define CHECK_RAY 1
# define CHECK_WALK 1 << 1

# define MAP_SPAWN 'x'
# define MAP_INVISIBLE_WALL 'i'

#endif
