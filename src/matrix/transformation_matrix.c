/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 19:14:34 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		build_scale_matrix(t_matrix m, double x, double y, double z)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void		build_translation_matrix(t_matrix m, double x, double y, double z)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = x;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = y;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = z;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void		compose_matrices(t_matrix transform, t_matrix scale,
t_matrix rotation, t_matrix translation)
{
	t_matrix	res;

	matrix_multiply(res, rotation, scale);
	matrix_multiply(transform, translation, res);
}

void		build_transformation_matrix(t_matrix transform, t_transform t)
{
	t_matrix	scale;
	t_matrix	rotation;
	t_matrix	translation;

	build_scale_matrix(scale, t.scale.x, t.scale.y, t.scale.z);
	build_rotation_matrix(rotation, t.rotation.x, t.rotation.y, t.rotation.z);
	build_translation_matrix(translation, t.translation.x,
	t.translation.y, t.translation.z);
	compose_matrices(transform, scale, rotation, translation);
}
