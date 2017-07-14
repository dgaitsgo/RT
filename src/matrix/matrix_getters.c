/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/10 19:30:46 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

t_vector	get_scale_vector(t_matrix m)
{
	return (new_vector(m[0][0], m[1][1], m[2][2]));
}

t_vector	get_translation_vector(t_matrix m)
{
	return (new_vector(m[0][3], m[1][3], m[2][3]));
}

t_vector	get_right_vector(t_matrix m)
{
	return (new_vector(m[0][0], m[1][0], m[2][0]));
}

t_vector	get_up_vector(t_matrix m)
{
	return (new_vector(m[0][1], m[1][1], m[2][1]));
}

t_vector	get_backward_vector(t_matrix m)
{
	return (new_vector(m[0][2], m[1][2], m[2][2]));
}
