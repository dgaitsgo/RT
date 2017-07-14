/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bound_entire_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		bound_entire_scene(t_scene *scene)
{
	t_object	*object;
	t_bbox		final;
	t_bbox		current;

	object = scene->root_object;
	set_vector(&final.min, REALLY_BIG, REALLY_BIG, REALLY_BIG);
	set_vector(&final.max, REALLY_SMALL, REALLY_SMALL, REALLY_SMALL);
	while (object)
	{
		current = *object->bbox;
		final.min = vector_min(current.min, final.min);
		final.max = vector_max(current.max, final.max);
		object = object->next;
	}
	scene->bbox = final;
}
