/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_ops2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:05:51 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector			vector_pow(t_vector a, double n)
{
	t_vector	res;

	res.x = pow(a.x, n);
	res.y = pow(a.y, n);
	res.z = pow(a.z, n);
	return (res);
}

void				zero_out_vectors(t_vector **v, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		set_vector(v[i], 0, 0, 0);
		i++;
	}
}

t_vector			vector_add_4(t_vector a, t_vector b, t_vector c, t_vector d)
{
	return (vector_add(d, vector_add(vector_add(a, b), c)));
}

t_vector			vector_add_3(t_vector a, t_vector b, t_vector c)
{
	return (vector_add(vector_add(a, b), c));
}

t_vector			average_vectors(t_vector **v, int max)
{
	int			i;
	t_vector	res;

	i = 0;
	set_vector(&res, 0, 0, 0);
	while (i < max)
	{
		res = vector_add(*v[i], res);
		i++;
	}
	res = vector_const_divide(res, max);
	return (res);
}
