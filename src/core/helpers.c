/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/23 18:11:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void					initialize_to_zero_2(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

void					multi_free_4(void *addr1, void *addr2,
						void *addr3, void *addr4)
{
	free_if(addr1);
	free_if(addr2);
	free_if(addr3);
	free_if(addr4);
}

void					free_obj_data_mem(t_obj_data *od)
{
	free_if(od->vertices);
	free_if(od->normals);
	free_if(od->face_indexes);
	free_if(od->normal_indexes);
	free_if(od);
}
