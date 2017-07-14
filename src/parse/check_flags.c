/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:26:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"
#include "flags.h"

void	check_camera_flags(t_camera *camera)
{
	if (!BIT_CHECK(camera->flags, ORIGIN_DEFINED))
		camera->origin = new_vector(0, 0, 0);
	if (!BIT_CHECK(camera->flags, DIRECTION_DEFINED))
		camera->direction = unit_vector(new_vector(0, 0, -1));
	if (!BIT_CHECK(camera->flags, FOV_DEFINED))
		camera->fov = FOV;
	if (!BIT_CHECK(camera->flags, TRANSFORM_DEFINED))
		camera->transformation =
	new_transformation(new_vector(1, 1, 1),
	new_vector(0, 0, 0), new_vector(0, 0, 0));
}

void	check_scene_flags(t_scene *scene)
{
	return ;
}

void	check_transformation_flags(t_transform *transformation)
{
	if (!BIT_CHECK(transformation->flags, SCALE_DEFINED))
		transformation->scale = new_vector(1, 1, 1);
	if (!BIT_CHECK(transformation->flags, ROTATION_DEFINED))
		transformation->rotation = new_vector(0, 0, 0);
	if (!BIT_CHECK(transformation->flags, TRANSLATION_DEFINED))
		transformation->translation = new_vector(0, 0, 0);
}

void	check_material_flags(t_material material)
{
	if (!BIT_CHECK(material.flags, LAMBERT_DEFINED))
		material.lambert = random_double(0.4);
	if (!BIT_CHECK(material.flags, SPECULAR_DEFINED))
		material.specular = random_double(0.2);
	if (!BIT_CHECK(material.flags, AMBIENT_DEFINED))
		material.ambient = random_double(0.3);
	if (!BIT_CHECK(material.flags, REFLECTIVE_DEFINED))
		material.reflective = random_double(0.7);
	if (!BIT_CHECK(material.flags, COLOR_DEFINED))
		material.texture.color_1 = random_color();
	rgb_to_normal(&material.texture.color_1);
}
