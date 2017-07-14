/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/28 16:41:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_bbox		transform_bbox(t_bbox bbox, t_matrix m)
{
	t_bbox		transed_bbox;
	t_vector	scale;
	t_vector	translation;
	t_pointbox	b;

	translation = get_translation_vector(m);
	b.xmin = vector_scale(get_right_vector(m), bbox.min.x);
	b.xmax = vector_scale(get_right_vector(m), bbox.max.x);
	b.ymin = vector_scale(get_up_vector(m), bbox.min.y);
	b.ymax = vector_scale(get_up_vector(m), bbox.max.y);
	b.zmin = vector_scale(get_backward_vector(m), bbox.min.z);
	b.zmax = vector_scale(get_backward_vector(m), bbox.max.z);
	transed_bbox.min = vector_add_4(vector_min(b.xmin, b.xmax),
	vector_min(b.ymin, b.ymax), vector_min(b.zmin, b.zmax), translation);
	transed_bbox.max = vector_add_4(vector_max(b.xmin, b.xmax),
	vector_max(b.ymin, b.ymax), vector_max(b.zmin, b.zmax), translation);
	return (transed_bbox);
}
