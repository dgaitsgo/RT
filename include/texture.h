/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:59:18 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 11:43:52 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "vector.h"
# include <SDL2/SDL.h>

enum			e_texture_type
{
	SIMPLE,
	EXTERN,
	MARBLE,
	PURE_NOISE,
	WOOD,
};

typedef struct			s_uv
{
	double				u;
	double				v;
}						t_uv;

typedef struct			s_texture
{
	t_vector			color_1;
	t_vector			color_2;
	int					type;
	int					flags;
	SDL_Surface			*text_img;
	t_vector			repetition;
	double				turb_power;
	double				turb_size;
}						t_texture;

t_vector				calc_perl(t_vector point, t_texture texture,
									unsigned char hash[512]);
double					p_noise_3d(double x, double y, double z,
									unsigned char hash[512]);

#endif
