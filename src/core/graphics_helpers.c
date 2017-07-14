/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 11:16:24 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double		clamp(double x, double min_value, double max_value)
{
	return (MIN(MAX(x, min_value), max_value));
}

double		smooth_step(double edge0, double edge1, double x)
{
	double t;

	t = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return (t * t * (3.0 - 2.0 * t));
}

t_vector	lerp(t_vector x, t_vector y, double a)
{
	return (vector_add(x, vector_scale(vector_subtract(y, x), a)));
}
