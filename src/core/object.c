/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 15:49:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_object			*new_object(int type)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	object->next = NULL;
	object->type = type;
	object->material = new_material();
	object->affine_group = new_affine_group();
	object->bbox = new_bbox();
	fetch_shape(object, type);
	return (object);
}

t_object			*add_object(t_scene *scene, int type)
{
	t_object	*new;

	scene->n_objects++;
	if (scene->n_objects)
	{
		scene->last->next = new_object(type);
		new = scene->last->next;
		scene->last = scene->last->next;
	}
	else
	{
		scene->root_object = new_object(type);
		new = scene->root_object;
		scene->last = scene->root_object;
	}
	return (new);
}
