/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 10:21:32 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void				randomize_vector(t_vector *vector, int i, t_light *light,
		int sh_grain)
{
	int			start_x;
	int			start_z;
	double		half_grain;

	half_grain = sh_grain / 2.0;
	start_x = i % sh_grain;
	start_z = i / sh_grain;
	vector->y = 0;
	vector->x = ((double)start_x) / half_grain - 1.0;
	vector->z = ((double)start_z) / half_grain - 1.0;
	if (sh_grain > 1)
	{
		vector->x = randomize(vector->x, 0, 1.0 / half_grain);
		vector->z = randomize(vector->z, 0, 1.0 / half_grain);
	}
	else
	{
		vector->x = 0;
		vector->z = 0;
	}
	*vector = matrix_transform_point(vector,
	light->transformation_matrix);
}

double				rand_ray_shooter(t_intersection intersection,
							t_scene *scene,
							t_light *light)
{
	t_ray			rand;
	t_intersection	nearest_occlusion;
	double			light_distance;
	int				i;
	double			scale;

	i = 0;
	scale = 0;
	while (i < scene->camera.sh_grain * scene->camera.sh_grain)
	{
		rand.origin = intersection.point;
		randomize_vector(&rand.direction, i, light, scene->camera.sh_grain);
		rand.distance = euclidean_distance3d(rand.origin, rand.direction);
		rand.direction =
			vector_subtract(rand.direction, rand.origin);
		rand.direction = unit_vector(rand.direction);
		rand.origin = vector_add(rand.origin,
				vector_scale(rand.direction, MIN_PRECISION));
		rand.type = SHADOW;
		nearest_occlusion = intersect_scene(rand, scene);
		if (nearest_occlusion.distance < rand.distance)
			scale++;
		i++;
	}
	return (1.0 - scale / (scene->camera.sh_grain * scene->camera.sh_grain));
}

void				shadowing(t_vector *tmp_color,
							t_intersection intersection,
							t_scene *scene,
							t_light *light)
{
	phong_shading(tmp_color, intersection, light);
	*tmp_color = vector_scale(*tmp_color,
		rand_ray_shooter(intersection, scene, light));
}
