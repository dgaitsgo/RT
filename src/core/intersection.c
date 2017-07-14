/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:33:15 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"

t_inter				init_inter(void)
{
	t_inter		inter;

	reset_intersection(&inter.min);
	reset_intersection(&inter.max);
	inter.hit = 0;
	return (inter);
}

t_intersection		process_intersection(t_ray world_ray, t_object *object,
		t_inter (*fn_intersect_object)(t_ray, t_object *))
{
	t_intersection	intersection;
	t_inter			inter;

	inter =
	(*fn_intersect_object)(ray_world_to_object(world_ray, object), object);
	reset_intersection(&intersection);
	if (!inter.hit)
		return (intersection);
	if (inter.min.distance > MIN_PRECISION)
		intersection = inter.min;
	else if (inter.max.distance > MIN_PRECISION)
		intersection = inter.max;
	calculate_world_intersection(object, world_ray, &intersection);
	return (intersection);
}

void				calculate_world_intersection(t_object *object,
								t_ray world_ray, t_intersection *intersection)
{
	intersection->point = matrix_transform_point(&intersection->obj_space_point,
	object->affine_group.transformation);
	if (object->type != TRIANGLE)
	{
		intersection->normal = unit_vector(matrix_transform_direction(
		&intersection->normal,
		object->affine_group.inverse_scale_times_rotation));
	}
	intersection->distance = euclidean_distance3d(intersection->point,
	world_ray.origin);
}

t_ray				ray_world_to_object(t_ray world_ray, t_object *object)
{
	t_ray			obj_ray;

	obj_ray.origin = matrix_transform_point(&world_ray.origin,
	object->affine_group.inverse);
	obj_ray.direction = matrix_transform_direction(&world_ray.direction,
	object->affine_group.inverse);
	obj_ray.len = vector_length(obj_ray.direction);
	obj_ray.direction = unit_vector(obj_ray.direction);
	return (obj_ray);
}

t_intersection		new_intersection(void)
{
	t_intersection	i;

	i.object = NULL;
	i.distance = MAX_BOUND;
	return (i);
}
