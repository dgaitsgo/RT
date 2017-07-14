/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_group.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:42:14 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/15 15:31:23 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFFINE_GROUP_H
# define __AFFINE_GROUP_H

# include "matrix.h"
# include "transform.h"

typedef struct	s_affine_group
{
	t_matrix	transformation;
	t_matrix	inverse;
	t_matrix	inverse_scale_times_rotation;
	t_transform	trans_data;
}				t_affine_group;

t_affine_group	new_affine_group(void);
void			build_affine_group(t_affine_group *ag);

#endif
