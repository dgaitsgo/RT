/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:16:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:19:45 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHADER_H
# define __SHADER_H

# include "vector.h"
# include "texture.h"

typedef struct	s_material
{
	t_texture	texture;
	double		lambert;
	double		specular;
	double		ambient;
	double		reflective;
	double		refraction;
	int			flags;
}				t_material;

struct s_ray;

t_vector		sky_color(struct s_ray ray, unsigned char hash[512]);
t_material		new_material(void);

#endif
