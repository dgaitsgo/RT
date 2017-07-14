/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 14:33:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_plane			*new_canonical_plane(void)
{
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	plane->flags = 0;
	set_vector(&plane->point, 0, 0, 0);
	set_vector(&plane->normal, 0, 1, 0);
	return (plane);
}

t_sphere		*new_canonical_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->radius = 1;
	set_vector(&sphere->center, 0, 0, 0);
	sphere->flags = 0;
	return (sphere);
}

t_cylinder		*new_canonical_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->radius = 1;
	cylinder->height = 1;
	cylinder->flags = 0;
	return (cylinder);
}

t_cone			*new_canonical_cone(void)
{
	t_cone		*cone;

	cone = malloc(sizeof(t_cone));
	cone->radius = 1;
	cone->height = 1;
	cone->flags = 0;
	return (cone);
}

t_triangle		*new_canonical_triangle(void)
{
	t_triangle *triangle;

	triangle = malloc(sizeof(t_triangle));
	set_vector(&triangle->v0, -.5, -.5, 0);
	set_vector(&triangle->v1, .5, -.5, 0);
	set_vector(&triangle->v2, 0, .5, 0);
	set_vector(&triangle->normal, 0, 1, 0);
	return (triangle);
}
