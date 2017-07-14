/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:13:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:29:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OBJECT_H
# define __OBJECT_H

# include "transform.h"
# include "shader.h"
# include "matrix.h"
# include "bounding_box.h"
# include "intersection.h"
# include "affine_group.h"

struct s_ray;

typedef struct		s_object
{
	int				type;
	void			*shape;
	t_bbox			*bbox;
	t_material		material;
	t_affine_group	affine_group;
	int				(*intersection_routine)(struct s_ray t, t_intersection *i);
	struct s_object	*next;
}					t_object;

void				fetch_shape(t_object *object, int type);
t_object			*new_object(int type);
void				build_object_matrices(t_object *object);

#endif
