/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_uv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_uv			calc_sphere_uv(t_intersection *intersection)
{
	t_uv		uv;
	t_vector	tmp;

	tmp = vector_scale(intersection->obj_space_point, -1);
	uv.u = 0.5 + (atan2(tmp.z, tmp.x) / (2 * PI));
	uv.u = 1 - uv.u;
	uv.v = 0.5 - (asin(tmp.y) / (PI));
	return (uv);
}

t_uv			calc_plane_uv(t_intersection *intersection)
{
	t_uv		uv;
	t_vector	tmp;

	tmp = intersection->obj_space_point;
	uv.u = (tmp.x / 2) + 0.5;
	uv.v = (tmp.z / 2) + 0.5;
	return (uv);
}

t_uv			calc_cylinder_uv(t_intersection *intersection)
{
	t_uv		uv;
	t_vector	tmp;

	tmp = intersection->obj_space_point;
	if (tmp.z > -0.999 && tmp.z < 0.999)
	{
		uv.u = 0.5 + (atan2(tmp.y, tmp.x) / (2 * PI));
		uv.v = (-tmp.z / 2) + 0.5;
	}
	else
	{
		uv.u = (tmp.x / (2 + PI)) + 0.5;
		uv.v = (tmp.y / (2 + PI)) + 0.5;
	}
	return (uv);
}

t_uv			calc_cone_uv(t_intersection *intersection)
{
	t_uv		uv;
	t_vector	tmp;

	tmp = intersection->obj_space_point;
	if (tmp.z > -0.999 && tmp.z < 0.999)
	{
		uv.u = 0.5 + (atan2(tmp.x / (1 - tmp.z), tmp.y / (1 - tmp.z))
				/ (2 * PI));
		uv.v = tmp.z;
	}
	else
	{
		uv.u = (tmp.x / (2 + PI)) + 0.5;
		uv.v = (tmp.y / (2 + PI)) + 0.5;
	}
	return (uv);
}
