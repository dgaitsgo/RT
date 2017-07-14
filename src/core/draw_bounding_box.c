/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bounding_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 15:29:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"

void			draw_box_lines(t_vector *b, t_window *window)
{
	t_vector red;

	red = new_vector(255, 0, 0);
	draw_line(init_line(b[0].x, b[0].y, b[1].x, b[1].y), red, window);
	draw_line(init_line(b[0].x, b[0].y, b[2].x, b[2].y), red, window);
	draw_line(init_line(b[0].x, b[0].y, b[4].x, b[4].y), red, window);
	draw_line(init_line(b[1].x, b[1].y, b[3].x, b[3].y), red, window);
	draw_line(init_line(b[1].x, b[1].y, b[5].x, b[5].y), red, window);
	draw_line(init_line(b[2].x, b[2].y, b[3].x, b[3].y), red, window);
	draw_line(init_line(b[2].x, b[2].y, b[6].x, b[6].y), red, window);
	draw_line(init_line(b[3].x, b[3].y, b[7].x, b[7].y), red, window);
	draw_line(init_line(b[4].x, b[4].y, b[5].x, b[5].y), red, window);
	draw_line(init_line(b[4].x, b[4].y, b[6].x, b[6].y), red, window);
	draw_line(init_line(b[5].x, b[5].y, b[7].x, b[7].y), red, window);
	draw_line(init_line(b[6].x, b[6].y, b[7].x, b[7].y), red, window);
}

void			draw_bbox(t_vector *box, t_bbox bbox, t_scene *scene)
{
	int i;

	i = 0;
	box[0] = bbox.min;
	set_vector(&box[1], bbox.min.x, bbox.min.y, bbox.max.z);
	set_vector(&box[2], bbox.min.x, bbox.max.y, bbox.min.z);
	set_vector(&box[3], bbox.min.x, bbox.max.y, bbox.max.z);
	set_vector(&box[4], bbox.max.x, bbox.min.y, bbox.min.z);
	set_vector(&box[5], bbox.max.x, bbox.min.y, bbox.max.z);
	set_vector(&box[6], bbox.max.x, bbox.max.y, bbox.min.z);
	box[7] = bbox.max;
	while (i < 8)
	{
		box[i] = matrix_transform_point(&box[i],
		scene->camera.inverse_view_matrix);
		box[i] = matrix_transform_point(&box[i], scene->projection);
		box[i] = perspective_divide(box[i]);
		box[i] = matrix_transform_point(&box[i], scene->screen_space);
		i++;
	}
	draw_box_lines(box, &scene->window);
}

void			draw_csg_bbox(t_node *self, t_scene *scene)
{
	if (self->object)
		draw_bbox(scene->box_container, *self->object->bbox, scene);
	else
	{
		if (self->left)
			draw_csg_bbox(self->left, scene);
		if (self->right)
			draw_csg_bbox(self->right, scene);
	}
}

void			draw_all_bounding_boxes(t_scene *scene)
{
	t_object	*object;

	object = scene->root_object;
	while (object)
	{
		if (object->type == CSG_ELEM)
			draw_csg_bbox(object->shape, scene);
		else
			draw_bbox(scene->box_container, *object->bbox, scene);
		object = object->next;
	}
	draw_bbox(scene->box_container, scene->bbox, scene);
	return ;
}
