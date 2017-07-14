/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:56:19 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 10:58:11 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERSECTION_H
# define __INTERSECTION_H

# include "vector.h"
# include "ray.h"
# include "shapes.h"
# include "bounding_box.h"
# define MAX_CSG	40

struct s_object;

typedef struct		s_intersection
{
	int				id;
	struct s_object	*object;
	double			distance;
	char			inverted_normal;
	t_vector		point;
	t_vector		obj_space_point;
	t_vector		normal;
	t_vector		color;
	t_ray			ray;
	int				hit;
	double			previous_medium_density;
}					t_intersection;

typedef struct		s_inter
{
	t_intersection	min;
	t_intersection	max;
	char			hit;
	struct s_inter	*next;
}					t_inter;

typedef struct		s_scene_intersections
{
	struct s_inter	left[MAX_CSG];
	struct s_inter	right[MAX_CSG];
	struct s_inter	csg[MAX_CSG];
	int				left_stack;
	int				right_stack;
	int				csg_stack;
}					t_scene_intersections;

void				reset_intersection_counters(t_scene_intersections *i);
t_intersection		new_intersection();
void				copy_intersection(t_intersection *dst, t_intersection *src);
void				reset_intersection(t_intersection *i);
void				get_intersection_color(t_intersection *intersection,
											unsigned char hash[512]);

t_inter				init_inter(void);
int					intersect_cube(t_ray world_ray,
					t_intersection *intersection);

int					intersect_plane(t_ray world_ray,
					t_intersection *intersection);

int					intersect_sphere(t_ray world_ray,
					t_intersection *intersection);

int					intersect_cone(t_ray world_ray,
					t_intersection *intersection);

int					intersect_cylinder(t_ray world_ray,
					t_intersection *intersection);

int					intersect_triangle(t_ray world_ray,
					t_intersection *intersection);

int					intersect_bbox(t_ray ray,
					t_bbox b);
#endif
