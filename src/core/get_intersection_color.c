/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:22:46 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		get_color_from_uv(t_intersection *intersection, t_uv uv)
{
	SDL_Surface		*surface;
	unsigned char	*p;
	t_vector		color;
	int				x;
	int				y;

	surface = intersection->object->material.texture.text_img;
	x = (uv.u * surface->w) - (int)uv.u;
	y = (uv.v * surface->h) - (int)uv.v;
	p = surface->pixels;
	p += (x * surface->format->BytesPerPixel);
	p += (y * surface->pitch);
	color.x = *(p + 0);
	color.y = *(p + 1);
	color.z = *(p + 2);
	color.w = 1;
	rgb_to_normal(&color);
	return (color);
}

t_vector		get_texture_color(t_intersection *intersection)
{
	t_vector	tmp;
	t_uv		uv;
	t_vector	scale;

	scale = intersection->object->material.texture.repetition;
	if (intersection->object->type == SPHERE)
		uv = calc_sphere_uv(intersection);
	else if (intersection->object->type == PLANE)
		uv = calc_plane_uv(intersection);
	else if (intersection->object->type == CYLINDER)
		uv = calc_cylinder_uv(intersection);
	else if (intersection->object->type == CONE)
		uv = calc_cone_uv(intersection);
	uv.u *= scale.x;
	uv.u -= floor(uv.u);
	uv.v *= scale.y;
	uv.v -= floor(uv.v);
	return (get_color_from_uv(intersection, uv));
}

void			get_intersection_color(t_intersection *intersection,
										unsigned char hash[512])
{
	t_object	*object;

	object = intersection->object;
	if (object->material.texture.type == SIMPLE)
		intersection->color = object->material.texture.color_1;
	else if (object->material.texture.type >= MARBLE &&
		object->material.texture.type <= WOOD)
		intersection->color =
			calc_perl(intersection->point, object->material.texture, hash);
	else if (object->material.texture.type == EXTERN)
		intersection->color = get_texture_color(intersection);
	else
		intersection->color = new_vector(0, 0, 0);
}
