/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		init_color(double r, double g, double b)
{
	t_vector	c;
	double		color_scale;

	color_scale = 1.0 / 255;
	c.x = r * color_scale;
	c.y = g * color_scale;
	c.z = b * color_scale;
	return (c);
}

void			clamp_color(t_vector *color)
{
	double		over_flow;

	over_flow = largest(largest(color->x, color->y), color->z);
	color->x /= over_flow;
	color->y /= over_flow;
	color->z /= over_flow;
}

void			rgb_to_normal(t_vector *color)
{
	double scale;

	scale = 1.0 / 255.0;
	color->x *= scale;
	color->y *= scale;
	color->z *= scale;
}

void			normal_to_rgb(t_vector *color)
{
	color->x *= 255.0;
	color->y *= 255.0;
	color->z *= 255.0;
}

int				under_floor(t_vector *color)
{
	if (color->x < 0.0)
		return (1);
	if (color->y < 0.0)
		return (1);
	if (color->z < 0.0)
		return (1);
	return (0);
}
