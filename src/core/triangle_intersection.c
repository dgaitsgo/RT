/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 18:45:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	set_triangle_intersection_data(t_intersect_triangle it, t_ray obj_ray,
										t_intersection *intersection)
{
	intersection->distance = it.dist;
	intersection->point = solve_parametric(obj_ray, intersection->distance);
	intersection->normal = it.t.normal;
}

int		intersect_triangle(t_ray obj_ray, t_intersection *intersection)
{
	t_intersect_triangle it;

	it.t = *(t_triangle *)intersection->object->shape;
	it.edge1 = vector_subtract(it.t.v1, it.t.v0);
	it.edge2 = vector_subtract(it.t.v2, it.t.v0);
	it.pvec = vector_cross(obj_ray.direction, it.edge2);
	it.det = dot_product(it.edge1, it.pvec);
	if (it.det > -MIN_PRECISION && it.det < MIN_PRECISION)
		return (0);
	it.inv_det = 1.0 / it.det;
	it.tvec = vector_subtract(obj_ray.origin, it.t.v0);
	it.u = dot_product(it.tvec, it.pvec) * it.inv_det;
	if (it.u < 0.0 || it.u > 1.0)
		return (0);
	it.qvec = vector_cross(it.tvec, it.edge1);
	it.v = dot_product(obj_ray.direction, it.qvec) * it.inv_det;
	if (it.v < 0.0 || it.u + it.v > 1.0)
		return (0);
	it.dist = dot_product(it.edge2, it.qvec) * it.inv_det;
	if (it.dist > MIN_PRECISION)
	{
		set_triangle_intersection_data(it, obj_ray, intersection);
		return (1);
	}
	return (0);
}
