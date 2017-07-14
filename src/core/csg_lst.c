/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/19 15:05:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_scene_intersections	*csg_lst_add_union(t_scene_intersections *si,
									t_inter add)
{
	int		i;

	i = 0;
	while (i <= si->csg_stack)
	{
		if ((si->csg[i].min.distance <= add.min.distance) &&
				(add.min.distance <= si->csg[i].max.distance))
		{
			if (add.max.distance > si->csg[i].max.distance)
				si->csg[i].max = add.max;
			return (si);
		}
		i++;
	}
	return (csg_lst_add(si, add));
}

t_scene_intersections	*csg_lst_add(t_scene_intersections *si, t_inter add)
{
	si->csg_stack += 1;
	si->csg[si->csg_stack] = add;
	return (si);
}

t_inter					create_inter(t_intersection min, int inv_normal_min,
								t_intersection max, int inv_normal_max)
{
	t_inter		tmp;

	tmp.min = min;
	tmp.min.inverted_normal = inv_normal_min;
	tmp.max = max;
	tmp.max.inverted_normal = inv_normal_max;
	return (tmp);
}
