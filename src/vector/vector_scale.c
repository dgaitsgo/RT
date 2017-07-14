/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/10 19:40:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		vector_scale(t_vector a, double c)
{
	t_vector res;

	res.x = a.x * c;
	res.y = a.y * c;
	res.z = a.z * c;
	return (res);
}

t_vector		vector_inverse_scale(t_vector a, double c)
{
	t_vector	res;
	double		t;

	t = 1.0 / c;
	res.x = a.x * t;
	res.y = a.y * t;
	res.z = a.z * t;
	return (res);
}
