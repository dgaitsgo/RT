/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 15:48:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_obj_data		*new_obj_data(void)
{
	t_obj_data	*od;

	od = malloc(sizeof(t_obj_data));
	od->n_faces = 0;
	od->n_normals = 0;
	od->n_normal_indexes = 0;
	od->n_vertices = 0;
	return (od);
}
