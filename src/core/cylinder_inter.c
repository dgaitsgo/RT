/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:02:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

static void		set_up_cylinder_coefficients(t_quadratic *q, t_vector d,
		t_vector p)
{
	q->a = (d.x * d.x) + (d.y * d.y);
	q->b = 2 * ((p.x * d.x) + (p.y * d.y));
	q->c = (p.x * p.x) + (p.y * p.y) - 1;
}

static void		check_hit(t_quadratic q, double z0, double z1, t_inter *inter)
{
	double		t;

	if ((z0 <= -1 && z1 > -1) || (z0 > -1 && z0 < 1 && z1 < -1) ||
			(z0 > 1 && z1 < 1))
	{
		t = q.t1 + (q.t2 - q.t1) * (z0 + 1) / (z0 - z1);
		if (t > MIN_PRECISION)
		{
			add_inter(inter, t, BASE);
		}
	}
	if ((z0 >= 1 && z1 < 1) || (z0 > -1 && z0 < 1 && z1 > 1) ||
			(z0 < -1 && z1 > 1))
	{
		t = q.t1 + (q.t2 - q.t1) * (z0 - 1) / (z0 - z1);
		if (t > MIN_PRECISION)
		{
			add_inter(inter, t, CAP);
		}
	}
}

static void		find_hit(t_ray obj_ray, t_quadratic q, t_inter *inter)
{
	double	z0;
	double	z1;
	int		hit;

	z0 = obj_ray.origin.z + q.t1 * obj_ray.direction.z;
	z1 = obj_ray.origin.z + q.t2 * obj_ray.direction.z;
	check_hit(q, z0, z1, inter);
	if (z0 >= -1 && z0 <= 1)
		add_inter(inter, q.t1, SIDE);
	if (z1 >= -1 && z1 <= 1)
		add_inter(inter, q.t2, SIDE);
}

t_vector		cylinder_normal(t_vector point, int hit)
{
	if (hit == BASE)
		return (new_vector(0, 0, -1));
	else if (hit == SIDE)
		return (new_vector(point.x, point.y, 0));
	else if (hit == CAP)
		return (new_vector(0, 0, 1));
	return (new_vector(0, 0, 0));
}

t_inter			inter_cylinder(t_ray obj_ray, t_object *object)
{
	t_quadratic	q;
	t_inter		inter;

	inter = init_inter();
	set_up_cylinder_coefficients(&q, obj_ray.direction, obj_ray.origin);
	if (solve_quadratic(&q) > 0)
	{
		find_hit(obj_ray, q, &inter);
		fill_inter(&inter.min, object, obj_ray);
		fill_inter(&inter.max, object, obj_ray);
		inter.hit = 1;
	}
	return (inter);
}
