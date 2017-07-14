/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:10:16 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		set_vector(t_vector *res, double x, double y, double z)
{
	res->x = x;
	res->y = y;
	res->z = z;
}

void		copy_vector(t_vector *dst, t_vector *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

t_vector	new_vector(double x, double y, double z)
{
	t_vector n;

	n.x = x;
	n.y = y;
	n.z = z;
	n.w = 0;
	return (n);
}

t_vector	new_point(double x, double y, double z, double w)
{
	t_vector n;

	n.x = x;
	n.y = y;
	n.z = z;
	n.w = 1;
	return (n);
}

t_vector	*new_vector_ptr(double x, double y, double z)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
