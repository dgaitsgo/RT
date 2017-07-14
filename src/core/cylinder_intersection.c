/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

void		set_up_cylinder_coefficients(t_quadratic *q, t_vector d, t_vector p)
{
	q->a = d.x * d.x + d.y * d.y;
	q->b = 2 * (p.x * d.x + p.y * d.y);
	q->c = p.x * p.x + p.y * p.y - 1;
}

int			check_base_hit(t_quadratic q, double z0, double z1, double *t)
{
	if (z1 > -1)
	{
		*t = q.t1 + (q.t2 - q.t1) * (z0 + 1) / (z0 - z1);
		if (*t > MIN_PRECISION)
			return (BASE);
	}
	return (MISS);
}

int			check_cap_hit(t_quadratic q, double z0, double z1, double *t)
{
	if (z1 < 1)
	{
		*t = q.t1 + (q.t2 - q.t1) * (z0 - 1) / (z0 - z1);
		if (*t > MIN_PRECISION)
			return (CAP);
	}
	return (MISS);
}

int			find_hit(t_ray obj_ray, t_quadratic q, double *t)
{
	double	z0;
	double	z1;
	int		hit;

	hit = 0;
	z0 = obj_ray.origin.z + q.t1 * obj_ray.direction.z;
	z1 = obj_ray.origin.z + q.t2 * obj_ray.direction.z;
	if (z0 <= -1)
	{
		if (!(hit = check_base_hit(q, z0, z1, t)))
			return (MISS);
	}
	if (z0 >= -1 && z0 <= 1)
	{
		*t = q.t1;
		hit = SIDE;
	}
	else if (z0 > 1)
	{
		if (!(hit = check_cap_hit(q, z0, z1, t)))
			return (MISS);
	}
	return (hit);
}

int			intersect_cylinder(t_ray obj_ray,
t_intersection *intersection)
{
	t_quadratic	q;
	int			hit;
	double		t;

	set_up_cylinder_coefficients(&q,
	obj_ray.direction, obj_ray.origin);
	if (!solve_quadratic(&q))
		return (MISS);
	hit = find_hit(obj_ray, q, &t);
	if (hit)
	{
		intersection->point = solve_parametric(obj_ray, t);
		if (hit == BASE)
			set_vector(&intersection->normal, 0, 0, -1);
		else if (hit == SIDE)
			set_vector(&intersection->normal,
			intersection->point.x, intersection->point.y, 0);
		else if (hit == CAP)
			set_vector(&intersection->normal, 0, 0, 1);
		intersection->distance = t;
		return (HIT);
	}
	return (MISS);
}
