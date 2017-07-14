/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 18:32:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		clean_si(t_scene_intersections *si)
{
	int		i;

	i = si->left_stack;
	while (i >= 0)
	{
		si->left[i] = init_inter();
		i--;
	}
	i = si->right_stack;
	while (i >= 0)
	{
		si->right[i] = init_inter();
		i--;
	}
	i = si->csg_stack;
	while (i >= 0)
	{
		si->csg[i] = init_inter();
		i--;
	}
	si->left_stack = -1;
	si->right_stack = -1;
	si->csg_stack = -1;
}

void		add_to_tab(t_inter inter, int tab_csg, t_scene_intersections *si)
{
	if (tab_csg == LST_LEFT)
	{
		si->left_stack++;
		si->left[si->left_stack] = inter;
	}
	if (tab_csg == LST_RIGHT)
	{
		si->right_stack++;
		si->right[si->right_stack] = inter;
	}
	if (tab_csg == LST_CSG)
	{
		si->csg_stack++;
		si->csg[si->csg_stack] = inter;
	}
}

void		move_csg_to_left(t_scene_intersections *si)
{
	int		i;

	i = 0;
	while (i <= si->csg_stack)
	{
		si->left[i] = si->csg[i];
		i++;
	}
	si->csg_stack = -1;
	si->left_stack = i - 1;
}

void		move_csg_to_right(t_scene_intersections *si)
{
	int		i;

	i = 0;
	while (i <= si->csg_stack)
	{
		si->right[i] = si->csg[i];
		i++;
	}
	si->csg_stack = -1;
	si->right_stack = i - 1;
}

void		self_handle(t_node self, t_ray world_ray,
							t_scene_intersections *si)
{
	t_inter	inter;

	if (self.object)
	{
		inter = calculate_world_inter(world_ray,
				self.intersect(ray_world_to_object(world_ray, self.object),
					self.object));
		if (inter.hit)
			add_to_tab(inter, LST_CSG, si);
	}
	else
	{
		if (self.left)
		{
			self_handle(*self.left, world_ray, si);
			move_csg_to_left(si);
		}
		if (self.right)
		{
			self_handle(*self.right, world_ray, si);
			move_csg_to_right(si);
		}
		self.csg_op(0, 0, si);
	}
}
