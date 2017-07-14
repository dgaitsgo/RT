/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:29:28 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:23:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "threads.h"

t_intersection	inter_scene(t_node *all, t_ray ray)
{
	t_intersection			intersection;
	t_scene_intersections	si;
	int						i;

	i = 0;
	reset_intersection_counters(&si);
	reset_intersection(&intersection);
	self_handle(*all, ray, &si);
	while (i <= si.csg_stack && !intersection.object)
	{
		if (si.csg[i].min.distance > MIN_PRECISION)
			intersection = si.csg[i].min;
		else if (si.csg[i].max.distance > MIN_PRECISION)
			intersection = si.csg[i].max;
		else
			i++;
	}
	intersection.ray = ray;
	if (intersection.inverted_normal)
		intersection.normal = vector_scale(intersection.normal, -1);
	return (intersection);
}

t_vector		trace_container(t_ray ray, t_scene *scene,
t_vector *color, int depth)
{
	t_intersection	intersection;

	if (depth > MAX_DEPTH)
		return (*color);
	intersection = intersect_scene(ray, scene);
	if (intersection.object == NULL)
	{
		return (sky_color(ray, scene->hash));
	}
	return (*shader(intersection, scene, color, depth));
}

int				i_was_a_baller(t_intersection *curr_inter,
				t_intersection *best_inter, t_ray ray)
{
	if (curr_inter->distance < best_inter->distance &&
	(ray.type != SHADOW || curr_inter->object->material.refraction == 0))
		return (1);
	return (0);
}

t_intersection	intersect_scene(t_ray ray, t_scene *scene)
{
	t_intersection		curr_inter;
	t_intersection		best_inter;
	t_object			*current_object;

	reset_intersection(&best_inter);
	current_object = scene->root_object;
	while (current_object)
	{
		reset_intersection(&curr_inter);
		curr_inter.object = current_object;
		if ((intersect_bbox(ray, scene->bbox)))
		{
			if (test_intersection(scene, current_object, ray, &curr_inter))
			{
				if (ray.type == SHADOW && ray.distance > curr_inter.distance
						&& curr_inter.object->material.refraction == 0)
					return (curr_inter);
				if (i_was_a_baller(&curr_inter, &best_inter, ray))
					copy_intersection(&best_inter, &curr_inter);
			}
		}
		current_object = current_object->next;
	}
	return (best_inter);
}

void			*render(void *arg)
{
	t_thread_env	e;
	t_ray			ray;
	int				cpy_x;
	int				cpy_y;

	e = *(t_thread_env*)arg;
	cpy_y = e.y;
	while (cpy_y < e.max_y)
	{
		cpy_x = e.x;
		while (cpy_x < e.max_x)
		{
			e.color = init_color(0, 0, 0);
			ray = generate_primary_ray(e.camera, cpy_x, cpy_y);
			e.color = trace_container(ray, e.scene, &e.color, 0);
			process_color(&e.color, &e.scene->camera.film);
			put_pixel(e.window, new_vector(cpy_x, cpy_y, ray.z), e.color, 0);
			cpy_x++;
		}
		cpy_y++;
	}
	pthread_exit(0);
}
