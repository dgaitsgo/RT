/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_to_trianlges.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:34:21 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	update_bboxes(t_scene *scene, t_bbox bbox, int first_triangle)
{
	t_object	*object;
	int			i;

	i = 0;
	object = scene->root_object;
	while (i < first_triangle)
	{
		object = object->next;
		i++;
	}
	while (object)
	{
		*object->bbox = bbox;
		object->affine_group = scene->mesh->affine_group;
		object->material = scene->mesh->material;
		object = object->next;
	}
}

void	set_triangle(t_triangle *t, t_obj_data *od, t_affine_group *ag, int i)
{
	t->v0 = matrix_transform_point(&od->vertices[od->face_indexes[i]],
	ag->transformation);
	t->v1 = matrix_transform_point(&od->vertices[od->face_indexes[i + 1]],
	ag->transformation);
	t->v2 = matrix_transform_point(&od->vertices[od->face_indexes[i + 2]],
	ag->transformation);
}

void	transform_and_push_mesh(t_scene *scene,
								t_obj_data *od,
								t_affine_group *ag,
								t_bbox mesh_bbox)
{
	int				i;
	int				n;
	int				first_triangle;
	t_triangle		*triangle;
	t_object		*object;

	initialize_to_zero_2(&i, &n);
	first_triangle = scene->n_objects + 1;
	while (i < od->n_faces)
	{
		object = add_object(scene, TRIANGLE);
		triangle = (t_triangle *)object->shape;
		set_triangle(triangle, od, ag, i);
		mesh_bbox.min = vector_min(mesh_bbox.min,
		vector_min(triangle->v0, triangle->v1));
		mesh_bbox.max = vector_max(mesh_bbox.max,
		vector_max(triangle->v0, triangle->v1));
		triangle->normal =
		unit_vector(matrix_transform_direction(
		&od->normals[od->normal_indexes[n]],
		ag->inverse_scale_times_rotation));
		i += 3;
		n++;
	}
	update_bboxes(scene, mesh_bbox, first_triangle);
}
