/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

void	set_up_sphere_coefficients(t_quadratic *q, t_vector d, t_vector p)
{
	q->a = 1;
	q->b = 2 * dot_product(d, p);
	q->c = dot_product(p, p) - 1;
}

int		intersect_sphere(t_ray obj_ray, t_intersection *intersection)
{
	t_quadratic		q;
	int				hit;

	set_up_sphere_coefficients(&q, obj_ray.direction, obj_ray.origin);
	if ((hit = solve_quadratic(&q)))
	{
		intersection->point = solve_parametric(obj_ray, q.t1);
		intersection->distance = q.t1;
		intersection->normal = unit_vector(intersection->point);
	}
	return (hit);
}
