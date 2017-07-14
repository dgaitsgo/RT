/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:20:34 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_material		new_material(void)
{
	t_material	m;

	m.texture.color_1 = init_color(255, 255, 255);
	m.texture.color_2 = init_color(0, 0, 0);
	m.texture.type = SIMPLE;
	m.texture.text_img = NULL;
	m.texture.repetition = new_vector(2, 2, 5);
	m.texture.turb_size = 16.f;
	m.texture.turb_power = 64.f;
	m.lambert = 0;
	m.specular = 0;
	m.ambient = 0;
	m.reflective = 0;
	m.refraction = 0;
	m.flags = 0;
	return (m);
}
