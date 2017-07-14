/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 20:39:03 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

static int		clip_plane(t_vector o)
{
	if (o.x < -1 || o.x > 1 || o.y < -1 || o.y > 1 || o.z < -1 || o.z > 1)
		return (0);
	return (1);
}

void			set_inter(double dom, double t,
						t_object *object, t_inter *inter)
{
	dom < 0 ? set_vector(&inter->min.normal, 0, -1, 0) :
	set_vector(&inter->min.normal, 0, 1, 0);
	inter->min.normal = unit_vector(inter->min.normal);
	inter->min.distance = t;
	inter->min.object = object;
	inter->min.inverted_normal = 0;
	inter->min.hit = 1;
	inter->max = inter->min;
	inter->hit = 1;
}

t_inter			inter_plane(t_ray obj_ray, t_object *object)
{
	double		dom;
	double		t;
	t_inter		inter;

	inter = init_inter();
	dom = dot_product(obj_ray.direction, UP_VECTOR);
	t = dot_product(vector_scale(obj_ray.origin, -1), UP_VECTOR) / dom;
	if ((t > MIN_PRECISION) && (t < MAX_BOUND))
	{
		inter.min.obj_space_point = solve_parametric(obj_ray, t);
		if (clip_plane(inter.min.obj_space_point))
			set_inter(dom, t, object, &inter);
	}
	return (inter);
}
