/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:50:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:36:34 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAY_H
# define __RAY_H

# include "object.h"
# include "vector.h"
# include "camera.h"

struct s_object;

enum				e_ray_type
{
	PRIMARY,
	SHADOW,
	REFRACTED,
	REFLECTED,
};

typedef struct		s_ray
{
	double			len;
	double			distance;
	double			z;
	t_vector		origin;
	t_vector		direction;
	int				type;
}					t_ray;

t_ray				ray_world_to_object(t_ray world_ray,
					struct s_object *object);
t_vector			solve_parametric(t_ray ray, double t);
t_ray				generate_primary_ray(t_camera *camera, double x, double y);

#endif
