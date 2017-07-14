/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 19:16:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	position_from_matrix(t_matrix m)
{
	return (new_vector(m[1][3], m[2][3], m[3][3]));
}

int			find_longest_axis(t_matrix m)
{
	double	big;

	big = largest(largest(m[0][0], m[1][1]), m[2][2]);
	if (big == m[0][0])
		return (X_AXIS);
	else if (big == m[1][1])
		return (Y_AXIS);
	else
		return (Z_AXIS);
}
