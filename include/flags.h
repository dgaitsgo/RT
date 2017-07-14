/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:52:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:26:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FLAGS_H
# define __FLAGS_H

# include "ray_trace.h"

# define BIT_SET(a,b) ((a) |= (1<<(b)))
# define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
# define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
# define BIT_CHECK(a,b) ((a) & (1<<(b)))

enum	e_scene_flags
{
	CAMERA_DEFINED,
	WINDOW_DEFINED,
	ANTI_ALIASING,
};

enum	e_window_flags
{
	WIDTH_DEFINED,
	HEIGHT_DEFINED,
};

enum	e_camera_flags
{
	FOV_DEFINED,
	ORIGIN_DEFINED,
	DIRECTION_DEFINED,
};

enum	e_element_flags
{
	ID_DEFINED,
	MATERIAL_DEFINED,
	TRANSFORM_DEFINED = 12,
	INFINITE_DEFINED,
};

enum	e_material_flags
{
	COLOR_DEFINED,
	LAMBERT_DEFINED,
	SPECULAR_DEFINED,
	AMBIENT_DEFINED,
	REFLECTIVE_DEFINED,
};

enum	e_cone_flags
{
	ANGLE_DEFINED,
};

enum	e_transform_flags
{
	SCALE_DEFINED,
	ROTATION_DEFINED,
	TRANSLATION_DEFINED,
};

void	check_camera_flags(t_camera *camera);
void	check_scene_flags(t_scene *scene);
void	check_window_flags(t_window *window);
void	check_transformation_flags(t_transform *transformation);

void	check_material_flags(t_material material);
void	check_cylinder_flags(t_cylinder *cylinder);
void	check_cone_flags(t_cone *cone);
void	check_plane_flags(t_plane *plane);
void	check_object_flags(t_object *object);

#endif
