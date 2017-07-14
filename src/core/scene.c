/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:55:28 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/21 17:11:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ray_trace.h"

void	initialize_intersection_fn_pointers(t_scene *scene)
{
	scene->intersect_fn_pointers[SPHERE] = inter_sphere;
	scene->intersect_fn_pointers[PLANE] = inter_plane;
	scene->intersect_fn_pointers[CYLINDER] = inter_cylinder;
	scene->intersect_fn_pointers[CONE] = inter_cone;
}

void	reset_intersection_counters(t_scene_intersections *i)
{
	i->left_stack = -1;
	i->right_stack = -1;
	i->csg_stack = -1;
}

void	initialize_scene(t_scene *scene)
{
	scene->n_lights = 0;
	scene->n_objects = -1;
	scene->flags = 0;
	scene->mesh = new_mesh();
	scene->light = malloc(sizeof(t_light *) * 2);
	scene->light[0] = new_light(POINT);
	scene->light[1] = new_light(POINT);
	scene->camera.flags = 0;
	scene->window.flags = 0;
	scene->root_object = NULL;
	scene->last = NULL;
	scene->box_container = malloc(sizeof(t_vector) * 8);
	default_camera(&scene->camera);
	init_hash_table(scene->hash);
	initialize_intersection_fn_pointers(scene);
}
