/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:23:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	calculate_lambert(t_intersection intersection,
								t_vector light)
{
	double		lambert_amt;
	double		contribution;
	t_vector	lambert;

	lambert_amt = 0;
	contribution = 0;
	lambert = new_vector(0, 0, 0);
	contribution = dot_product(unit_vector(vector_subtract(light,
	intersection.point)), intersection.normal);
	if (contribution > 0)
		lambert_amt += contribution;
	lambert = vector_scale(intersection.color, lambert_amt);
	return (lambert);
}

t_vector	calculate_specular(t_intersection intersection,
								t_vector light)
{
	t_vector	l;
	t_vector	r;
	double		dot;
	double		spec;

	l = unit_vector(vector_subtract(light, intersection.point));
	r = vector_add(vector_scale(vector_scale(intersection.normal,
	dot_product(l, intersection.normal)), -2), l);
	dot = dot_product(intersection.ray.direction, r);
	if (dot > 0)
	{
		spec = powf(dot, 20) * intersection.object->material.specular;
		if (spec)
		{
			return (vector_scale(intersection.color, spec));
		}
	}
	return (new_vector(0, 0, 0));
}

void		phong_shading(t_vector *color,
							t_intersection intersection,
							t_light *light)
{
	if (intersection.object->material.lambert)
	{
		*color = vector_add(*color,
		calculate_lambert(intersection, light->position));
	}
	if (intersection.object->material.specular)
	{
		*color = vector_add(*color,
		calculate_specular(intersection, light->position));
	}
}
