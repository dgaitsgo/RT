/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 14:30:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		cannonical_bbox(t_bbox *bbox)
{
	bbox->min = new_point(-1, -1, -1, 1);
	bbox->max = new_point(1, 1, 1, 1);
	bbox->min = vector_const_add(bbox->min, -0.0001);
	bbox->max = vector_const_add(bbox->max, 0.0001);
}

void		set_bbox(t_bbox *box, t_vector min, t_vector max)
{
	box->min = min;
	box->max = max;
}

t_bbox		extreme_bbox(void)
{
	t_bbox	b;

	set_vector(&b.min, REALLY_BIG, REALLY_BIG, REALLY_BIG);
	set_vector(&b.max, REALLY_SMALL, REALLY_SMALL, REALLY_SMALL);
	return (b);
}

t_bbox		*new_bbox(void)
{
	t_bbox	*bbox;

	bbox = malloc(sizeof(t_bbox));
	cannonical_bbox(bbox);
	return (bbox);
}
