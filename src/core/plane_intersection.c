/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:25:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

int		clip_plane(t_vector o)
{
	if (o.x < -1 || o.x > 1 || o.y < -1 || o.y > 1 || o.z < -1 || o.z > 1)
		return (0);
	return (1);
}

int		intersect_plane(t_ray obj_ray, t_intersection *intersection)
{
	double		dom;
	double		t;

	dom = dot_product(obj_ray.direction, UP_VECTOR);
	t = dot_product(vector_scale(obj_ray.origin, -1), UP_VECTOR) / dom;
	if ((t < MIN_PRECISION) || (t > MAX_BOUND))
		return (0);
	else
	{
		intersection->point = solve_parametric(obj_ray, t);
		if (!clip_plane(intersection->point))
			return (0);
		dom < 0 ? set_vector(&intersection->normal, 0, -1, 0) :
		set_vector(&intersection->normal, 0, 1, 0);
		intersection->normal = unit_vector(intersection->normal);
		intersection->distance = t;
		return (1);
	}
	return (0);
}
