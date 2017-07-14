/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:35:58 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/23 14:37:15 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		csg_intersection(int left, int right, t_scene_intersections *si)
{
	if (left > si->left_stack || !SI_LEFT.hit ||
			right > si->right_stack || !SI_RIGHT.hit)
		return ;
	if (SI_LEFT.min.distance < SI_RIGHT.min.distance)
	{
		if (SI_LEFT.max.distance < SI_RIGHT.min.distance)
			return (csg_intersection(left + 1, right, si));
		else if (SI_LEFT.max.distance <= SI_RIGHT.max.distance)
			return (csg_intersection(left + 1, right, csg_lst_add(si,
			create_inter(SI_RIGHT.min, 0, SI_LEFT.max, 0))));
		else
			return (csg_intersection(left, right + 1, csg_lst_add(si,
				create_inter(SI_RIGHT.min, 0, SI_RIGHT.max, 0))));
	}
	else
	{
		if (SI_RIGHT.max.distance < SI_LEFT.min.distance)
			return (csg_intersection(left, right + 1, si));
		else if (SI_RIGHT.max.distance <= SI_LEFT.max.distance)
			return (csg_intersection(left, right + 1, csg_lst_add(si,
				create_inter(SI_LEFT.min, 0, SI_RIGHT.max, 0))));
		else
			return (csg_intersection(left + 1, right, csg_lst_add(si,
				create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
	}
}

void		csg_handle_union(int left, int right, t_scene_intersections *si)
{
	if (SI_LEFT.min.distance < SI_RIGHT.min.distance)
	{
		if (SI_LEFT.max.distance < SI_RIGHT.min.distance)
			return (csg_union(left + 1, right, csg_lst_add_union(si,
				create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
		else if (SI_LEFT.max.distance <= SI_RIGHT.max.distance)
			return (csg_union(left + 1, right, csg_lst_add_union(si,
				create_inter(SI_LEFT.min, 0, SI_RIGHT.max, 0))));
		else
			return (csg_union(left, right + 1, csg_lst_add_union(si,
				create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
	}
	else
	{
		if (SI_RIGHT.max.distance < SI_LEFT.min.distance)
			return (csg_union(left, right + 1, csg_lst_add_union(si,
				create_inter(SI_RIGHT.min, 0, SI_RIGHT.max, 0))));
		else if (SI_RIGHT.max.distance <= SI_LEFT.max.distance)
			return (csg_union(left, right + 1, csg_lst_add_union(si,
				create_inter(SI_RIGHT.min, 0, SI_LEFT.max, 0))));
		else
			return (csg_union(left + 1, right, csg_lst_add_union(si,
				create_inter(SI_RIGHT.min, 0, SI_RIGHT.max, 0))));
	}
}

void		csg_union(int left, int right, t_scene_intersections *si)
{
	if (left > si->left_stack || !SI_LEFT.hit)
	{
		if (right > si->right_stack || !SI_RIGHT.hit)
			return ;
		else
			return (csg_union(left, right + 1, csg_lst_add_union(si,
				create_inter(SI_RIGHT.min, 0, SI_RIGHT.max, 0))));
	}
	else if (right > si->right_stack || !SI_RIGHT.hit)
		return (csg_union(left + 1, right, csg_lst_add_union(si,
			create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
	else
		return (csg_handle_union(left, right, si));
}

void		csg_handle_diff(int left, int right, t_scene_intersections *si)
{
	if (SI_LEFT.min.distance < SI_RIGHT.min.distance)
	{
		if (SI_LEFT.max.distance < SI_RIGHT.min.distance)
			return (csg_difference(left + 1, right, csg_lst_add(si,
				create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
		else if (SI_LEFT.max.distance <= SI_RIGHT.max.distance)
			return (csg_difference(left + 1, right, csg_lst_add(si,
				create_inter(SI_LEFT.min, 0, SI_RIGHT.min, 1))));
		else
		{
			csg_lst_add(si, create_inter(SI_LEFT.min, 0, SI_RIGHT.min, 1));
			csg_lst_add(si, create_inter(SI_RIGHT.max, 1, SI_LEFT.max, 0));
			return (csg_difference(left, right + 1, si));
		}
	}
	else
	{
		if (SI_RIGHT.max.distance < SI_LEFT.min.distance)
			return (csg_difference(left, right + 1, si));
		else if (SI_RIGHT.max.distance < SI_LEFT.max.distance)
			return (csg_difference(left, right + 1, csg_lst_add(si,
					create_inter(SI_RIGHT.max, 1, SI_LEFT.max, 0))));
		else
			return (csg_difference(left + 1, right, si));
	}
}

void		csg_difference(int left, int right, t_scene_intersections *si)
{
	if (left > si->left_stack || !SI_LEFT.hit)
		return ;
	else if ((right > si->right_stack || !SI_RIGHT.hit) && (si->csg_stack == -1
			|| si->csg[0].max.distance != SI_LEFT.max.distance))
		return (csg_difference(left + 1, right,
				csg_lst_add(si, create_inter(SI_LEFT.min, 0, SI_LEFT.max, 0))));
	else if (right > si->right_stack || !SI_RIGHT.hit)
		return (csg_difference(left + 1, right, si));
	else
		return (csg_handle_diff(left, right, si));
}
