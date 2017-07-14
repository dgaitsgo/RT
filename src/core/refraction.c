/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:23:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		determine_n(t_object *obj, t_refraction_data *r, t_vector *normal)
{
	if (r->cos_i > 0.0)
	{
		r->density_1 = obj->material.refraction;
		r->density_2 = 1.0;
		*normal = vector_scale(*normal, -1.0);
	}
	else
	{
		r->density_1 = 1.0;
		r->density_2 = obj->material.refraction;
		r->cos_i = -(r->cos_i);
	}
	r->n = r->density_1 / r->density_2;
}

t_ray		inner_reflect(t_intersection intersection,
		t_vector normal, t_refraction_data r)
{
	t_ray	new_ray;

	new_ray.direction = unit_vector(intersection.ray.direction);
	new_ray.direction = unit_vector(vector_subtract(
				new_ray.direction, vector_scale(normal, (2.0 * r.cos_i))));
	new_ray.origin = vector_add(intersection.point,
		vector_scale(new_ray.direction, MIN_PRECISION));
	return (new_ray);
}

t_ray		calculate_refraction_ray(t_intersection intersection,
									t_refraction_data *r,
									t_vector *normal)
{
	t_ray	new_ray;
	double	rn;
	double	rt;

	r->reflectance = 0.0;
	r->transmittance = 0.0;
	if (r->sin_t2 < 0.0)
		return (new_ray = inner_reflect(intersection, *normal, *r));
	r->cos_t2 = sqrt(r->sin_t2);
	rn = (r->density_1 * r->cos_i - r->density_2 * r->cos_t2) /
		(r->density_1 * r->cos_i + r->density_2 * r->cos_t2);
	rt = (r->density_2 * r->cos_i - r->density_1 * r->cos_t2) /
		(r->density_2 * r->cos_i + r->density_1 * r->cos_t2);
	rn *= rn;
	rt *= rt;
	r->reflectance = (rn + rt) * 0.5;
	r->transmittance = 1.0 - r->reflectance;
	new_ray.direction = vector_add(vector_scale(intersection.ray.direction,
				r->n), vector_scale(*normal, (r->n * r->cos_i - r->cos_t2)));
	new_ray.direction = unit_vector(new_ray.direction);
	new_ray.origin = vector_add(intersection.point,
	vector_scale(new_ray.direction, MIN_PRECISION));
	return (new_ray);
}

void		refract(t_vector *color,
					t_intersection intersection,
					t_scene *scene,
					int depth)
{
	t_refraction_data	r;
	t_ray				refracted_ray;
	t_vector			normal;
	t_vector			s_color;
	t_vector			r_color;

	set_vector(&s_color, 0, 0, 0);
	set_vector(&r_color, 0, 0, 0);
	normal = intersection.normal;
	r.cos_i = dot_product(normal, intersection.ray.direction);
	determine_n(intersection.object, &r, &normal);
	r.sin_t2 = 1 - (r.n * r.n * (1.0 - (r.cos_i * r.cos_i)));
	if (depth < MAX_DEPTH)
	{
		refracted_ray = calculate_refraction_ray(intersection, &r, &normal);
		s_color = vector_scale(trace_container(
			refracted_ray, scene, &s_color, ++depth), r.transmittance);
		if (r.reflectance > 0.0)
			r_color = vector_scale(trace_container(
				inner_reflect(intersection, normal, r),
				scene, &r_color, ++depth), r.reflectance);
		*color = vector_add(vector_add(s_color, r_color), *color);
	}
}
