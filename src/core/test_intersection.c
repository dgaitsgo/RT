/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:35:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/05 18:43:45 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"

int		test_intersection(t_scene *scene, t_object *object, t_ray ray,
t_intersection *intersection)
{
	scene->stats.total_intersections++;
	ray.z = REALLY_BIG;
	if (object->type == TRIANGLE)
		intersection->hit = intersect_triangle(ray, intersection);
	else if (object->type == CSG_ELEM)
		*intersection = inter_scene(object->shape, ray);
	else
	{
		*intersection = process_intersection(ray, object,
				scene->intersect_fn_pointers[object->type]);
	}
	if (intersection->hit != MISS)
	{
		ray.z = intersection->point.z;
		intersection->ray = ray;
		return (1);
	}
	return (0);
}
