/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_transformations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/07 18:16:53 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	build_inverse_translation_matrix(t_matrix m,
double x, double y, double z)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = -x;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = -y;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = -z;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void	build_inverse_scale_matrix(t_matrix m, double x, double y, double z)
{
	m[0][0] = 1.0 / x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1.0 / y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1.0 / z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void	build_inverse_transformation_matrix(t_matrix inverse_transform,
t_transform t)
{
	t_matrix	inverse_scale;
	t_matrix	inverse_rotation;
	t_matrix	inverse_translation;
	t_matrix	res;

	build_inverse_scale_matrix(inverse_scale,
	t.scale.x, t.scale.y, t.scale.z);
	build_inverse_rotation_matrix(inverse_rotation,
	t.rotation.x, t.rotation.y, t.rotation.z);
	build_inverse_translation_matrix(inverse_translation,
	t.translation.x, t.translation.y, t.translation.z);
	matrix_multiply(res, inverse_rotation, inverse_translation);
	matrix_multiply(inverse_transform, inverse_scale, res);
}
