/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/17 16:45:54 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = (a.z * b.x) - (a.x * b.z);
	res.z = (a.x * b.y) - (a.y * b.x);
	return (res);
}

double		dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		vector_length(t_vector a)
{
	return (sqrt(dot_product(a, a)));
}

int			compare_vector(t_vector a, t_vector b)
{
	double	a_len;
	double	b_len;

	a_len = vector_length(a);
	b_len = vector_length(b);
	if (a_len == b_len)
		return (0);
	else if (a_len < b_len)
		return (-1);
	else
		return (1);
}

t_vector	unit_vector(t_vector a)
{
	return (vector_scale(a, 1 / vector_length(a)));
}
