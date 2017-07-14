/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/19 15:00:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "mesh.h"

int		max_elements(int type)
{
	if (type == PLANE)
		return (MAX_PLANE_ELEMENTS);
	else if (type == SPHERE)
		return (MAX_SPHERE_ELEMENTS);
	else if (type == CYLINDER)
		return (MAX_CYLINDER_ELEMENTS);
	else if (type == CONE)
		return (MAX_CONE_ELEMENTS);
	else if (type == TRIANGLE)
		return (MAX_TRIANGLE_ELEMENTS);
	else if (type == CUBE)
		return (MAX_CUBE_ELEMENTS);
	else if (type == MESH)
		return (MAX_MESH_ELEMENTS);
	return (0);
}

void	parse_obj_container(char **tokens, int *i, t_mesh *mesh)
{
	char	c[2];

	c[0] = '"';
	c[1] = '\0';
	if (expect(tokens[*i], c, i))
	{
		load_mesh(mesh->obj_data, tokens[*i]);
		if (mesh->obj_data != NULL)
		{
			if (next(tokens, c, i))
				;
		}
		else
			parse_error(MEMORY_ERROR, tokens, i);
	}
}

void	free_mesh_resources(t_mesh *mesh)
{
	t_obj_data *od;

	od = mesh->obj_data;
	free_obj_data_mem(od);
}

void	parse_mesh(char **tokens, int *i, t_scene *scene, int max_depth)
{
	t_mesh *mesh;

	mesh = scene->mesh;
	if (check(tokens[*i], "}") || max_depth == max_elements(MESH))
	{
		build_affine_group(&mesh->affine_group);
		transform_and_push_mesh(scene,
								scene->mesh->obj_data,
								&scene->mesh->affine_group,
								extreme_bbox());
		free_mesh_resources(scene->mesh);
		return ;
	}
	if (accept(tokens[*i], "url", i))
		parse_obj_container(tokens, i, mesh);
	else if (accept(tokens[*i], "Transformation", i))
		parse_transform_container(tokens, i, &mesh->affine_group.trans_data);
	else if (accept(tokens[*i], "Material", i))
		parse_material_container(tokens, i, &mesh->material);
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_mesh(tokens, i, scene, ++max_depth);
}

void	parse_primitive(char **tokens, int *i, t_object *object, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == max_elements(object->type))
	{
		build_affine_group(&object->affine_group);
		cannonical_bbox(object->bbox);
		*object->bbox =
		transform_bbox(*object->bbox, object->affine_group.transformation);
		return ;
	}
	else if (accept(tokens[*i], "Transformation", i))
		parse_transform_container(tokens, i, &object->affine_group.trans_data);
	else if (accept(tokens[*i], "Material", i))
		parse_material_container(tokens, i, &object->material);
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_primitive(tokens, i, object, ++max_depth);
}
