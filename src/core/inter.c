/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:30:04 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:32:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void				add_inter(t_inter *inter, double t, int hit)
{
	if (!inter->min.distance)
	{
		inter->min.distance = t;
		inter->min.hit = hit;
	}
	else if (t < inter->min.distance)
	{
		inter->max.distance = inter->min.distance;
		inter->max.hit = inter->min.hit;
		inter->min.distance = t;
		inter->min.hit = hit;
	}
	else
	{
		inter->max.distance = t;
		inter->max.hit = hit;
	}
}

t_intersection		convert_inter(t_ray world_ray, t_intersection touch)
{
	touch.point = matrix_transform_point(&touch.obj_space_point,
			touch.object->affine_group.transformation);
	touch.normal = unit_vector(matrix_transform_direction(
				&touch.normal,
				touch.object->affine_group.inverse_scale_times_rotation));
	if (touch.distance < 0)
		touch.distance = -1 *
			euclidean_distance3d(touch.point, world_ray.origin);
	else
		touch.distance = euclidean_distance3d(touch.point, world_ray.origin);
	return (touch);
}

t_inter				calculate_world_inter(t_ray world_ray, t_inter inter)
{
	t_intersection	tmp;

	if (!inter.hit)
		return (inter);
	inter.min = convert_inter(world_ray, inter.min);
	inter.max = convert_inter(world_ray, inter.max);
	if (inter.min.distance > inter.max.distance)
	{
		tmp = inter.max;
		inter.max = inter.min;
		inter.min = tmp;
	}
	return (inter);
}

void				fill_inter(t_intersection *i, t_object *object, t_ray ray)
{
	i->object = object;
	i->obj_space_point = solve_parametric(ray, i->distance);
	i->normal = cylinder_normal(i->obj_space_point, i->hit);
	i->inverted_normal = 0;
	i->hit = 1;
}
