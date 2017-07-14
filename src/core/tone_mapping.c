/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tone_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:13:42 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/05 18:44:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void			initialize_tone_map(t_tone_map *t)
{
	t->a = TONE_MAP_A;
	t->b = TONE_MAP_B;
	t->c = TONE_MAP_C;
	t->d = TONE_MAP_D;
	t->e = TONE_MAP_E;
	t->f = TONE_MAP_F;
	t->w = TONE_MAP_W;
	t->exposure = 1.0;
	t->gamma = GAMMA;
	t->white = ((t->w * (t->a * t->w + t->c * t->b) + t->d * t->e) /
	(t->w * (t->a * t->w + t->b) + t->d * t->f)) - t->e / t->f;
}

void			tone_map(t_vector *color, t_tone_map *t)
{
	t_vector	num;
	t_vector	denom;

	*color = vector_scale(*color, t->exposure);
	num = vector_const_add(vector_multiply(*color,
	vector_const_add(vector_scale(*color, t->a), t->c * t->b)), t->d * t->e);
	denom = vector_const_add(vector_multiply(*color,
	vector_const_add(vector_scale(*color, t->a), t->b)), t->d * t->f);
	*color = vector_divide(num, denom);
	*color = vector_const_add(*color, -(t->e / t->f));
	*color = vector_scale(*color, 1 / t->white);
	*color = vector_pow(*color, 1 / t->gamma);
}
