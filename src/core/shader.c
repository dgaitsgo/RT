/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:23:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

int				light_is_visible(t_intersection intersection,
							t_scene *scene,
							t_light *light)
{
	double			light_distance;
	t_ray			ray;
	t_intersection	light_intersection;

	ray.type = SHADOW;
	ray.origin = intersection.point;
	ray.direction =
	unit_vector(vector_subtract(light->position, intersection.point));
	light_distance = euclidean_distance3d(intersection.point, light->position);
	intersection = intersect_scene(ray, scene);
	if (intersection.distance > light_distance)
		return (1);
	return (0);
}

void			reflect(t_vector *color, t_intersection intersection,
t_scene *scene, int depth)
{
	t_vector		s_color;
	t_vector		r;
	t_ray			n;

	set_vector(&s_color, 0, 0, 0);
	r = vector_add(vector_scale(vector_scale(intersection.normal,
	dot_product(intersection.ray.direction, intersection.normal)), -2),
	intersection.ray.direction);
	n.type = REFLECTED;
	n.origin = vector_add(intersection.point, r);
	n.direction = r;
	n.direction = unit_vector(n.direction);
	s_color = trace_container(n, scene, &s_color, ++depth);
	*color = vector_add(*color, vector_multiply(vector_scale(s_color,
	intersection.object->material.reflective),
	intersection.color));
}

t_texture		initiate_texture(t_vector sky_color)
{
	t_texture	texture;

	texture.type = PURE_NOISE;
	texture.repetition = new_vector(10, 10, 10);
	texture.turb_size = 8;
	texture.color_2 = sky_color;
	texture.color_1 = init_color(255, 255, 255);
	return (texture);
}

t_vector		sky_color(t_ray ray, unsigned char hash[512])
{
	t_vector	sky;
	t_vector	ground;
	double		transition;
	t_vector	outdoors;
	t_texture	texture;

	sky = new_vector(0.52, 0.77, 1);
	ground = new_vector(0.12, 0.43, 1);
	transition = pow(smooth_step(0.02, .5, -ray.direction.y), 0.4);
	outdoors = vector_scale(lerp(ground, sky, transition), 1);
	texture = initiate_texture(outdoors);
	return (calc_perl(solve_parametric(ray, 1000), texture, hash));
}

t_vector		*shader(t_intersection intersection,
					t_scene *scene,
					t_vector *color,
					int depth)
{
	t_object		*object;
	int				i;
	t_vector		tmp_color;

	i = 0;
	object = intersection.object;
	get_intersection_color(&intersection, scene->hash);
	while (i < scene->n_lights)
	{
		set_vector(&tmp_color, 0, 0, 0);
		if ((object->material.reflective > 0.0) && (depth < MAX_DEPTH))
			reflect(&tmp_color, intersection, scene, depth);
		if ((object->material.refraction > 0.0) && (depth < MAX_DEPTH))
			refract(&tmp_color, intersection, scene, depth);
		shadowing(&tmp_color, intersection, scene, scene->light[i]);
		*color = vector_add(*color,
		vector_multiply(scene->light[i]->color, tmp_color));
		i++;
	}
	*color = vector_add(*color,
	vector_scale(intersection.color, object->material.ambient));
	return (color);
}
