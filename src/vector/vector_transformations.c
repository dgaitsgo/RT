/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:10:02 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		matrix_transform_raster_point(t_vector *pnt, t_matrix m)
{
	t_vector	inv;

	inv.x =
	pnt->x * m[0][0] + pnt->y * m[0][1] + pnt->z * m[0][2] + pnt->w * m[0][3];
	inv.y =
	pnt->x * m[1][0] + pnt->y * m[1][1] + pnt->z * m[1][2] + pnt->w * m[1][3];
	inv.z =
	pnt->x * m[2][0] + pnt->y * m[2][1] + pnt->z * m[2][2] + pnt->w * m[2][3];
	inv.w =
	pnt->x * m[3][0] + pnt->y * m[3][1] + pnt->z * m[3][2] + pnt->w * m[3][3];
	return (inv);
}

t_vector		matrix_transform_point(t_vector *pnt, t_matrix m)
{
	t_vector	inv;

	inv.x = pnt->x * m[0][0] + pnt->y * m[0][1] + pnt->z * m[0][2] + m[0][3];
	inv.y = pnt->x * m[1][0] + pnt->y * m[1][1] + pnt->z * m[1][2] + m[1][3];
	inv.z = pnt->x * m[2][0] + pnt->y * m[2][1] + pnt->z * m[2][2] + m[2][3];
	inv.w = 1;
	return (inv);
}

t_vector		matrix_transform_direction(t_vector *dir, t_matrix m)
{
	t_vector	inv;

	inv.x = dir->x * m[0][0] + dir->y * m[0][1] + dir->z * m[0][2];
	inv.y = dir->x * m[1][0] + dir->y * m[1][1] + dir->z * m[1][2];
	inv.z = dir->x * m[2][0] + dir->y * m[2][1] + dir->z * m[2][2];
	inv.w = 0;
	return (inv);
}
