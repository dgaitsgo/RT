/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/21 16:40:50 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		apply_camera_transform(t_camera *camera, t_transform transf)
{
	build_transformation_matrix(camera->view_matrix, transf);
	build_inverse_transformation_matrix(camera->inverse_view_matrix, transf);
	camera->origin = matrix_transform_point(&camera->origin,
	camera->view_matrix);
	camera->direction = unit_vector(matrix_transform_direction(
	&camera->direction, camera->view_matrix));
}

void		initialize_film(t_film *film)
{
	if (film->quantize == 1)
		film->color_map = gen_lowres_color_table();
}

void		default_camera(t_camera *camera)
{
	camera->sh_grain = 1;
	camera->visualize_bboxes = 0;
	camera->fov = FOV;
	camera->origin = new_vector(0, 0, 0);
	camera->direction = new_vector(0, 0, 1);
	camera->transformation = new_transformation(new_vector(1, 1, 1),
	new_vector(0, 0, 0), new_vector(0, 0, 0));
	initialize_tone_map(&camera->film.tone_map);
}

void		initialize_camera(t_camera *camera, t_window *window)
{
	apply_camera_transform(camera, camera->transformation);
	camera->eye =
	unit_vector(vector_subtract(camera->direction, camera->origin));
	camera->right = unit_vector(vector_cross(camera->eye, UP_VECTOR));
	camera->up = unit_vector(vector_cross(camera->right, camera->eye));
	camera->half_height = tan(degrees_to_radians(camera->fov / 2));
	camera->half_width = window->aspect_ratio * camera->half_height;
	camera->pixel_height =
	camera->half_height * 2 / (float)(window->height - 1);
	camera->pixel_width =
	camera->half_width * 2 / (float)(window->width - 1);
	initialize_film(&camera->film);
}
