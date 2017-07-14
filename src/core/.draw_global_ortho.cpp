/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_global_ortho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:54:00 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/02/06 15:54:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		draw_global_ortho(t_scene *scene)
{
	t_vector x_axis;
	t_vector y_axis;
	t_vector z_axis;
	t_vector origin;

	set_vector(&origin, 0, 0, 0);
	set_vector(&x_axis, 5, 0, 0);
	set_vector(&y_axis, 0, 5, 0);
	set_vector(&z_axis, 0, 0, 5);

	origin = matrix_transform_point(&origin, scene->camera.inverse_view_matrix);
	x_axis = matrix_transform_point(&x_axis, scene->camera.inverse_view_matrix);
	y_axis = matrix_transform_point(&y_axis, scene->camera.inverse_view_matrix);
	z_axis = matrix_transform_point(&z_axis, scene->camera.inverse_view_matrix);

	origin = matrix_transform_point(&origin, scene->projection);
	x_axis = matrix_transform_point(&x_axis, scene->projection);
	y_axis = matrix_transform_point(&y_axis, scene->projection);
	z_axis = matrix_transform_point(&z_axis, scene->projection);

	origin = perspective_divide(origin);
	x_axis = perspective_divide(x_axis);
	y_axis = perspective_divide(y_axis);
	z_axis = perspective_divide(z_axis);

	origin = matrix_transform_point(&origin, scene->screen_space);
	x_axis = matrix_transform_point(&x_axis, scene->screen_space);
	y_axis = matrix_transform_point(&y_axis, scene->screen_space);
	z_axis = matrix_transform_point(&z_axis, scene->screen_space);
	
	draw_line(init_line(origin.x, origin.y, x_axis.x, x_axis.y), new_vector(0, 255, 0),  &scene->window);
	draw_line(init_line(origin.x, origin.y, y_axis.x, y_axis.y), new_vector(0, 255, 0),  &scene->window);
	draw_line(init_line(origin.x, origin.y, z_axis.x, z_axis.y), new_vector(0, 255, 0),  &scene->window);
}
