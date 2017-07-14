/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 16:15:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

static void	set_up_sphere_coefficients(t_quadratic *q, t_vector d, t_vector p)
{
	q->a = 1;
	q->b = 2 * dot_product(d, p);
	q->c = dot_product(p, p) - 1;
}

static void	fill_touch(t_intersection *touch,
		t_object *object, double t, t_ray ray)
{
	touch->object = object;
	touch->distance = t;
	touch->obj_space_point = solve_parametric(ray, t);
	touch->normal = unit_vector(touch->obj_space_point);
	touch->hit = 1;
	touch->inverted_normal = 0;
}

t_inter		inter_sphere(t_ray obj_ray, t_object *object)
{
	t_quadratic	q;
	t_inter		inter;

	inter = init_inter();
	set_up_sphere_coefficients(&q, obj_ray.direction, obj_ray.origin);
	if (solve_quadratic(&q))
	{
		fill_touch(&inter.min, object, q.t1, obj_ray);
		fill_touch(&inter.max, object, q.t2, obj_ray);
		inter.hit = 1;
	}
	return (inter);
}
