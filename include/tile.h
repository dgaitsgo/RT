/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:44:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:45:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TILE_H
# define __TILE_H

# include "ray.h"
# include <pthread.h>

# define TILE_X 32
# define TILE_Y 32
# define TILE_AREA TILE_X * TILE_Y

typedef struct	s_title
{
	short		start_x;
	short		start_y;
	short		end_x;
	short		end_y;
	char		*frame_buffer;
	t_ray		ray[TILE_AREA];
	pthread_t	thread;
}				t_tile;

#endif
