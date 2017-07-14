/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 14:34:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		process_color(t_vector *color, t_film *f)
{
	if (under_floor(color))
		floor_color(color);
	if (out_of_gamut(color))
		clamp_color(color);
	if (f->ldr)
		tone_map(color, &f->tone_map);
	normal_to_rgb(color);
	if (f->quantize)
		*color = nearest_color_neighbor(f->color_map, *color);
}

void		floor_and_ceiling(t_vector *color)
{
	color->x = color->x < 0 ? 0 : color->x;
	color->y = color->y < 0 ? 0 : color->y;
	color->z = color->z < 0 ? 0 : color->z;
	color->x = color->x > 1 ? 1 : color->x;
	color->y = color->y > 1 ? 1 : color->y;
	color->z = color->z > 1 ? 1 : color->z;
}

int			out_of_gamut(t_vector *color)
{
	if (color->x > 1.0)
		return (1);
	if (color->y > 1.0)
		return (1);
	if (color->z > 1.0)
		return (1);
	return (0);
}

void		floor_color(t_vector *color)
{
	double	offset;

	offset = 0 - smallest(smallest(color->x, color->y), color->z);
	color->x += offset;
	color->y += offset;
	color->z += offset;
}

t_vector	moy_color(t_vector *color, double sub)
{
	t_vector	new_color;

	if (sub < 2)
		return (*color);
	new_color = vector_const_divide(*color, sub);
	return (new_color);
}
