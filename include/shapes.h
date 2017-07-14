/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:17:58 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:46:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include "vector.h"
# include "object.h"

typedef struct
{
	int				flags;
	t_vector		point;
	t_vector		normal;
}					t_plane;

typedef struct
{
	int				flags;
	double			radius;
	t_vector		center;
}					t_sphere;

typedef struct
{
	int				flags;
	double			height;
	double			radius;
}					t_cone;

typedef struct
{
	int				flags;
	double			height;
	double			radius;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		v0;
	t_vector		v1;
	t_vector		v2;
	t_vector		normal;
	t_matrix		*m;
}					t_triangle;

typedef struct
{
	int				flags;
}					t_cube;

typedef struct		s_intersect_triangle
{
	t_vector		edge1;
	t_vector		edge2;
	t_vector		edge3;
	t_vector		tvec;
	t_vector		pvec;
	t_vector		qvec;
	t_triangle		t;
	double			dist;
	double			u;
	double			v;
	double			det;
	double			inv_det;
}					t_intersect_triangle;

t_triangle			*new_canonical_triangle(void);
t_cube				*new_canonical_cube(void);
t_plane				*new_canonical_plane(void);
t_sphere			*new_canonical_sphere(void);
t_cylinder			*new_canonical_cylinder(void);
t_cone				*new_canonical_cone(void);

#endif
