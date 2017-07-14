/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"

void				fetch_shape(t_object *object, int type)
{
	if (type == PLANE)
		object->shape = new_canonical_plane();
	if (type == SPHERE)
		object->shape = new_canonical_sphere();
	if (type == CYLINDER)
		object->shape = new_canonical_cylinder();
	if (type == CONE)
		object->shape = new_canonical_cone();
	if (type == TRIANGLE)
		object->shape = new_canonical_triangle();
	if (type == CUBE)
		object->shape = new_canonical_cube();
	if (type == MESH)
		object->shape = new_mesh();
	if (type == CSG_ELEM)
		object->shape = new_csg();
}
