/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:31:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/10 14:06:34 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		primitive_element(int e)
{
	if (e == PLANE || e == SPHERE || e == CYLINDER ||
		e == CONE || e == TRIANGLE || e == CUBE)
		return (1);
	return (0);
}

void	parse_element_container(char **tokens,
								int *i,
								t_scene *scene,
								int element)
{
	t_object		*object;

	if (expect(tokens[*i], "{", i))
	{
		if (element == WINDOW_ELEM)
			parse_window(tokens, i, &scene->window, 0);
		else if (element == CAMERA_ELEM)
			parse_camera(tokens, i, &scene->camera, 0);
		else if (element == LIGHT_ELEM)
			parse_light(tokens, i, 0, scene);
		else if (primitive_element(element))
			parse_primitive(tokens, i, add_object(scene, element), 0);
		else if (element == MESH)
			parse_mesh(tokens, i, scene, 0);
		else if (element == CSG_ELEM)
		{
			object = add_object(scene, element);
			parse_csg_container(tokens, i, (t_node *)object->shape);
		}
		if (expect(tokens[*i], "}", i))
			return ;
	}
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
}

int		check_other_elements(char **tokens, int *i, t_scene *scene)
{
	if (accept(tokens[*i], "Cylinder", i))
		parse_element_container(tokens, i, scene, CYLINDER);
	else if (accept(tokens[*i], "Cone", i))
		parse_element_container(tokens, i, scene, CONE);
	else if (accept(tokens[*i], "Triangle", i))
		parse_element_container(tokens, i, scene, TRIANGLE);
	else if (accept(tokens[*i], "Mesh", i))
		parse_element_container(tokens, i, scene, MESH);
	else
		return (0);
	return (1);
}

int		element(char **tokens, int *i, t_scene *scene)
{
	if (tokens[*i] == NULL)
	{
		check_scene_flags(scene);
		return (1);
	}
	if (accept(tokens[*i], "Window", i))
		parse_element_container(tokens, i, scene, WINDOW_ELEM);
	else if (accept(tokens[*i], "Camera", i))
		parse_element_container(tokens, i, scene, CAMERA_ELEM);
	else if (accept(tokens[*i], "Light", i))
		parse_element_container(tokens, i, scene, LIGHT_ELEM);
	else if (accept(tokens[*i], "Csg", i))
		parse_element_container(tokens, i, scene, CSG_ELEM);
	else if (accept(tokens[*i], "Plane", i))
		parse_element_container(tokens, i, scene, PLANE);
	else if (accept(tokens[*i], "Sphere", i))
		parse_element_container(tokens, i, scene, SPHERE);
	else if (check_other_elements(tokens, i, scene))
		;
	else
		parse_error(UNKNOWN_ELEMENT, tokens, i);
	return (element(tokens, i, scene));
}

int		parse_scene(char **tokens, t_scene *scene)
{
	int i;

	i = 0;
	if (element(tokens, &i, scene))
	{
		if (scene->n_objects == -1)
		{
			free(scene->root_object);
			free(scene->last);
			free(scene->box_container);
			scene->root_object = NULL;
			scene->last = NULL;
			scene->box_container = NULL;
		}
		return (1);
	}
	return (0);
}
