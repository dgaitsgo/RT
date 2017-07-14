/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:59:09 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 10:50:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSG_H
# define CSG_H

# include "ray.h"

typedef struct			s_node
{
	t_inter				(*intersect)(t_ray i, t_object *);
	t_object			*object;
	void				(*csg_op)(int left, int right,
									t_scene_intersections *si);
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

enum					e_csg_tab
{
	LST_LEFT,
	LST_RIGHT,
	LST_CSG,
};

t_inter					create_inter(t_intersection min, int inv_normal_min,
								t_intersection max, int inv_normal_max);
void					free_csg_lst(t_inter *beg);
t_scene_intersections	*csg_lst_add(t_scene_intersections *si, t_inter add);
t_scene_intersections	*csg_lst_add_union(t_scene_intersections *si,
											t_inter add);
void					print_lst(t_inter *beg, char name);
void					self_handle(t_node self, t_ray world_ray,
									t_scene_intersections *si);
void					add_inter(t_inter *inter, double t, int hit);
t_inter					calculate_world_inter(t_ray world_ray, t_inter inter);

void					csg_intersection(int left, int right,
										t_scene_intersections *si);
void					csg_difference(int left, int right,
										t_scene_intersections *si);
void					csg_union(int left, int right,
										t_scene_intersections *si);

void					free_node(t_node *node);
t_node					*new_csg(void);
#endif
