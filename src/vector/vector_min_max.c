/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 11:15:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	vector_max(t_vector a, t_vector b)
{
	t_vector	max;

	max.x = MAX(a.x, b.x);
	max.y = MAX(a.y, b.y);
	max.z = MAX(a.z, b.z);
	max.w = MAX(a.w, b.w);
	return (max);
}

t_vector	vector_min(t_vector a, t_vector b)
{
	t_vector	min;

	min.x = MIN(a.x, b.x);
	min.y = MIN(a.y, b.y);
	min.z = MIN(a.z, b.z);
	min.w = MIN(a.w, b.w);
	return (min);
}
