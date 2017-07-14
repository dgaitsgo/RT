/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 14:36:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

static void		setup_cone_coefficients(t_quadratic *q,
t_vector p, t_vector d)
{
	q->a = d.x * d.x + d.y * d.y - d.z * d.z;
	q->b = 2 * d.x * p.x + 2 * d.y * p.y - 2 * d.z * p.z;
	q->c = p.x * p.x + p.y * p.y - p.z * p.z;
}

static void		check_cap_intersection(t_quadratic q,
t_ray ray, t_inter *inter)
{
	t_vector	d;
	t_vector	p;

	p = ray.origin;
	d = ray.direction;
	q.c = (1 - p.z) / d.z;
	q.a = p.x + q.c * d.x;
	q.b = p.y + q.c * d.y;
	if ((q.a * q.a + q.b * q.b) <= 1 && q.c > MIN_PRECISION && q.c < MAX_BOUND)
		add_inter(inter, q.c, CAP);
}

static t_vector	calculate_cone_normal(t_intersection touch)
{
	t_vector	normal;

	if (touch.hit == SIDE)
	{
		normal = touch.obj_space_point;
		normal.z = -1;
		normal = unit_vector(normal);
	}
	if (touch.hit == CAP)
		normal = new_vector(0, 0, 1);
	return (normal);
}

static int		analyze_roots(t_quadratic q, t_ray obj_ray, t_inter *inter)
{
	double	z1;
	double	z2;
	int		hit;

	hit = MISS;
	z1 = obj_ray.origin.z + q.t1 * obj_ray.direction.z;
	z2 = obj_ray.origin.z + q.t2 * obj_ray.direction.z;
	if (z1 > MIN_PRECISION && z1 <= 1)
		add_inter(inter, q.t1, SIDE);
	if (z2 > MIN_PRECISION && z2 <= 1)
		add_inter(inter, q.t2, SIDE);
	check_cap_intersection(q, obj_ray, inter);
	return (hit);
}

t_inter			inter_cone(t_ray obj_ray, t_object *object)
{
	t_quadratic	q;
	t_inter		inter;

	inter = init_inter();
	setup_cone_coefficients(&q, obj_ray.origin, obj_ray.direction);
	if (!solve_quadratic(&q))
		return (inter);
	analyze_roots(q, obj_ray, &inter);
	if (inter.min.distance)
	{
		inter.min.object = object;
		inter.min.obj_space_point =
		solve_parametric(obj_ray, inter.min.distance);
		inter.min.normal = calculate_cone_normal(inter.min);
		inter.min.inverted_normal = 0;
		inter.max.object = object;
		inter.max.obj_space_point =
		solve_parametric(obj_ray, inter.max.distance);
		inter.max.normal = calculate_cone_normal(inter.max);
		inter.max.inverted_normal = 0;
		inter.hit = 1;
		inter.min.hit = 1;
		inter.max.hit = 1;
	}
	return (inter);
}
