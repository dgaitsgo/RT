/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:34:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/03 15:35:45 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void				p_noise_bump(t_intersection *intersection, t_scene *scene)
{
	t_vector		b;
	int				i;
	t_vector		p;
	unsigned char	*s;

	s = scene->hash;
	p = intersection->point;
	i = 10;
	b.x = p_noise_3d(p.x - i, p.y, p.z, s) - p_noise_3d(p.x + i, p.y, p.z, s);
	b.y = p_noise_3d(p.x, p.y - i, p.z, s) - p_noise_3d(p.x, p.y + i, p.z, s);
	b.z = p_noise_3d(p.x, p.y, p.z - i, s) - p_noise_3d(p.x, p.y, p.z + i, s);
	intersection->normal = unit_vector(vector_add(intersection->normal, b));
}

void				wave_it(t_intersection *intersection)
{
	double			repetition;
	double			intensity;

	repetition = 20;
	intensity = 2;
	intersection->normal.x +=
		(cos(repetition * intersection->obj_space_point.x) - 1) * intensity;
	intersection->normal = unit_vector(intersection->normal);
}
