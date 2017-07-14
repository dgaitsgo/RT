/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:28:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:34:19 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MESH_H
# define __MESH_H

# include "shapes.h"
# include "shader.h"
# include "obj_data.h"
# include "affine_group.h"

typedef struct		s_mesh
{
	t_bbox			*bbox;
	t_obj_data		*obj_data;
	t_material		material;
	t_affine_group	affine_group;
}					t_mesh;

t_mesh				*new_mesh(void);
int					intersect_mesh(t_ray obj_ray, t_intersection *intersection);
#endif
