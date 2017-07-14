/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:10:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		setup_cone_coefficients(t_quadratic *q,
t_vector p, t_vector d)
{
	q->a = d.x * d.x + d.y * d.y - d.z * d.z;
	q->b = 2 * d.x * p.x + 2 * d.y * p.y - 2 * d.z * p.z;
	q->c = p.x * p.x + p.y * p.y - p.z * p.z;
}

void		check_cap_intersection(int *hit, t_quadratic q,
t_ray ray, double *t)
{
	t_vector	d;
	t_vector	p;

	p = ray.origin;
	d = ray.direction;
	q.c = (1 - p.z) / d.z;
	q.a = p.x + q.c * d.x;
	q.b = p.y + q.c * d.y;
	if ((q.a * q.a + q.b * q.b) <= 1 && q.c > MIN_PRECISION && q.c < MAX_BOUND)
	{
		if (*t > q.c)
		{
			*t = q.c;
			*hit = CAP;
		}
	}
}

void		calculate_cone_normal(int hit, t_intersection *intersection)
{
	if (hit == SIDE)
	{
		intersection->normal = intersection->point;
		intersection->normal.z = -1;
		intersection->normal = unit_vector(intersection->normal);
	}
	if (hit == CAP)
		intersection->normal = new_vector(0, 0, 1);
}

int			analyze_roots(t_quadratic q, t_ray obj_ray, double *t)
{
	double	z1;
	double	z2;
	int		hit;

	hit = MISS;
	*t = FLT_MAX;
	z1 = obj_ray.origin.z + q.t1 * obj_ray.direction.z;
	z2 = obj_ray.origin.z + q.t2 * obj_ray.direction.z;
	if (q.t1 > MIN_PRECISION && q.t1 < MAX_BOUND &&
	z1 > MIN_PRECISION && z1 <= 1)
	{
		*t = q.t1;
		hit = SIDE;
	}
	else if (z2 > MIN_PRECISION && z2 < 1 && q.t2 > MIN_PRECISION)
	{
		*t = q.t2;
		hit = SIDE;
	}
	check_cap_intersection(&hit, q, obj_ray, t);
	return (hit);
}

int			intersect_cone(t_ray obj_ray, t_intersection *intersection)
{
	int			hit;
	double		t;
	t_quadratic q;

	hit = 0;
	setup_cone_coefficients(&q,
	obj_ray.origin, obj_ray.direction);
	if (!solve_quadratic(&q))
		return (MISS);
	hit = analyze_roots(q, obj_ray, &t);
	if (hit)
	{
		intersection->point = solve_parametric(obj_ray, t);
		calculate_cone_normal(hit, intersection);
		return (HIT);
	}
	return (MISS);
}
