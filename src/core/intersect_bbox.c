/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 11:20:02 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

int			ray_inside_bbox(t_ray ray, t_bbox bbox)
{
	return (bbox.min.x <= ray.origin.x && bbox.max.x >= ray.origin.x &&
		bbox.min.y <= ray.origin.y && bbox.max.y >= ray.origin.y &&
		bbox.min.z <= ray.origin.z && bbox.max.z >= ray.origin.z);
}

int			intersect_bbox(t_ray ray, t_bbox bbox)
{
	t_vector		invdir;
	double			tmin;
	double			tmax;
	t_extremebox	b;

	tmin = -INFINITY;
	tmax = INFINITY;
	invdir = vector_inverse(ray.direction);
	if (ray_inside_bbox(ray, bbox))
		return (1);
	b.xmin = (bbox.min.x - ray.origin.x) * invdir.x;
	b.xmax = (bbox.max.x - ray.origin.x) * invdir.x;
	tmin = MIN(b.xmin, b.xmax);
	tmax = MAX(b.xmin, b.xmax);
	b.ymin = (bbox.min.y - ray.origin.y) * invdir.y;
	b.ymax = (bbox.max.y - ray.origin.y) * invdir.y;
	tmin = MAX(tmin, MIN(b.ymin, b.ymax));
	tmax = MIN(tmax, MAX(b.ymin, b.ymax));
	b.zmin = (bbox.min.z - ray.origin.z) * invdir.z;
	b.zmax = (bbox.max.z - ray.origin.z) * invdir.z;
	tmin = MAX(tmin, MIN(b.zmin, b.zmax));
	tmax = MIN(tmax, MAX(b.zmin, b.zmax));
	return (tmax >= tmin);
}
