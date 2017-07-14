/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/03 14:34:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_cube	*new_canonical_cube(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	cube->flags = 0;
	return (cube);
}
