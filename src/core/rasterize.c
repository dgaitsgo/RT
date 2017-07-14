/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 15:55:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	perspective_divide(t_vector v)
{
	t_vector	p;

	p = v;
	p.x = p.x / p.z;
	p.y = p.y / p.z;
	return (p);
}

void		rasterize(t_scene *scene)
{
	draw_all_bounding_boxes(scene);
}
