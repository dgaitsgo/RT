/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_matrix_build.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:22:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/05 19:16:51 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		build_normal_to_world(t_matrix norm_to_world, t_transform t)
{
	t_matrix	inverse_scale;
	t_matrix	rotation;

	build_inverse_scale_matrix(inverse_scale, t.scale.x, t.scale.y, t.scale.z);
	build_rotation_matrix(rotation, t.rotation.x, t.rotation.y, t.rotation.z);
	matrix_multiply(norm_to_world, rotation, inverse_scale);
}

void		build_light_matrices(t_scene *scene)
{
	int i;

	i = 0;
	while (i < scene->n_lights)
	{
		build_transformation_matrix(scene->light[i]->transformation_matrix,
				scene->light[i]->transformation);
		i++;
	}
}

void		build_affine_group(t_affine_group *ag)
{
	build_transformation_matrix(ag->transformation, ag->trans_data);
	build_inverse_transformation_matrix(ag->inverse, ag->trans_data);
	build_normal_to_world(ag->inverse_scale_times_rotation, ag->trans_data);
}
