/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_rotation_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 19:09:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		rotate_inverse_x(t_matrix rx, double x)
{
	rx[0][0] = 1;
	rx[0][1] = 0;
	rx[0][2] = 0;
	rx[0][3] = 0;
	rx[1][0] = 0;
	rx[1][1] = (double)cos(x);
	rx[1][2] = (double)sin(x);
	rx[1][3] = 0;
	rx[2][0] = 0;
	rx[2][1] = -(double)sin(x);
	rx[2][2] = (double)cos(x);
	rx[2][3] = 0;
	rx[3][0] = 0;
	rx[3][1] = 0;
	rx[3][2] = 0;
	rx[3][3] = 1;
}

void		rotate_inverse_y(t_matrix ry, double y)
{
	ry[0][0] = (double)cos(y);
	ry[0][1] = 0;
	ry[0][2] = -(double)sin(y);
	ry[0][3] = 0;
	ry[1][0] = 0;
	ry[1][1] = 1;
	ry[1][2] = 0;
	ry[1][3] = 0;
	ry[2][0] = (double)sin(y);
	ry[2][1] = 0;
	ry[2][2] = (double)cos(y);
	ry[2][3] = 0;
	ry[3][0] = 0;
	ry[3][1] = 0;
	ry[3][2] = 0;
	ry[3][3] = 1;
}

void		rotate_inverse_z(t_matrix rz, double z)
{
	rz[0][0] = (double)cos(z);
	rz[0][1] = (double)sin(z);
	rz[0][2] = 0;
	rz[0][3] = 0;
	rz[1][0] = -(double)sin(z);
	rz[1][1] = (double)cos(z);
	rz[1][2] = 0;
	rz[1][3] = 0;
	rz[2][0] = 0;
	rz[2][1] = 0;
	rz[2][2] = 1;
	rz[2][3] = 0;
	rz[3][0] = 0;
	rz[3][1] = 0;
	rz[3][2] = 0;
	rz[3][3] = 1;
}

void		build_inverse_rotation_matrix(t_matrix inverse_rotation,
double x, double y, double z)
{
	t_matrix	rx;
	t_matrix	ry;
	t_matrix	rz;
	t_matrix	res;

	rotate_inverse_x(rx, degrees_to_radians(x));
	rotate_inverse_y(ry, degrees_to_radians(y));
	rotate_inverse_z(rz, degrees_to_radians(z));
	matrix_multiply(res, ry, rz);
	matrix_multiply(inverse_rotation, rx, res);
}
