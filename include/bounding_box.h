/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:40:32 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 10:46:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BOUNDING_BOX_H
# define __BOUNDING_BOX_H

# include "vector.h"

typedef struct
{
	t_vector	min;
	t_vector	max;
}	t_bbox;

typedef struct
{
	t_vector	xmin;
	t_vector	ymin;
	t_vector	zmin;
	t_vector	xmax;
	t_vector	ymax;
	t_vector	zmax;
}	t_pointbox;

typedef struct
{
	double	xmin;
	double	ymin;
	double	zmin;
	double	xmax;
	double	ymax;
	double	zmax;
}			t_extremebox;

void		cannonical_bbox(t_bbox *bbox);
t_bbox		*new_bbox(void);
void		init_bbox(t_bbox *box, t_vector min, t_vector max);
t_bbox		transform_bbox(t_bbox box, t_matrix m);
t_bbox		extreme_bbox(void);

#endif
