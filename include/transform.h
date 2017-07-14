/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:02:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:24:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TRANSFORM_H
# define __TRANSFORM_H

# include "vector.h"
# include "matrix.h"

typedef struct
{
	int			flags;
	t_vector	scale;
	t_vector	rotation;
	t_vector	translation;
}				t_transform;

void			build_normal_to_world(t_matrix norm_to_world, t_transform t);
void			default_transformation(t_transform *transformation);
void			rotate_x(t_matrix rx, double x);
void			rotate_y(t_matrix ry, double y);
void			rotate_z(t_matrix rz, double z);
void			build_rotation_matrix(t_matrix rotation,
				double x, double y, double z);

void			build_scale_matrix(t_matrix m, double x, double y, double z);
void			build_translation_matrix(t_matrix m,
				double x, double y, double z);

void			build_transformation_matrix(t_matrix transform, t_transform t);

void			rotate_inverse_x(t_matrix rx, double x);
void			rotate_inverse_y(t_matrix ry, double y);
void			rotate_inverse_z(t_matrix rz, double z);
void			build_inverse_rotation_matrix(t_matrix inverse_rotation,
				double x, double y, double z);

void			build_inverse_translation_matrix(t_matrix m,
				double x, double y, double z);

void			build_inverse_scale_matrix(t_matrix m,
				double x, double y, double z);

void			build_inverse_transformation_matrix(t_matrix inverse_transform,
				t_transform t);

t_transform		new_transformation(t_vector scale,
				t_vector rotation, t_vector translation);
#endif
