/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 18:22:20 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_film(char **tokens, int *i, t_film *film, int max)
{
	if (check(tokens[*i], "}") || max == MAX_FILM_ELEMENTS)
	{
		accept(tokens[*i], "}", i);
		return ;
	}
	if (accept(tokens[*i], "ldr", i))
		parse_int_container(tokens, i, &film->ldr, range(0, 1));
	if (accept(tokens[*i], "quantize", i))
		parse_int_container(tokens, i, &film->quantize, range(0, 1));
	if (accept(tokens[*i], "exposure", i))
		parse_double_container(tokens, i,
		&film->tone_map.exposure, range(MIN_PRECISION, 3));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_film(tokens, i, film, max++);
}

void	parse_film_container(char **tokens, int *i, t_film *film)
{
	if (accept(tokens[*i], "{", i))
	{
		parse_film(tokens, i, film, 0);
	}
}

void	parse_camera(char **tokens, int *i, t_camera *camera, int max)
{
	if (check(tokens[*i], "}") || max == MAX_CAMERA_ELEMENTS)
		return ;
	if (accept(tokens[*i], "fov", i))
		parse_double_container(tokens, i, &camera->fov, range(1, 179));
	else if (accept(tokens[*i], "origin", i))
		parse_vector(tokens, i, &camera->origin, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "direction", i))
		parse_vector(tokens, i, &camera->direction, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "Film", i))
		parse_film_container(tokens, i, &camera->film);
	else if (accept(tokens[*i], "Transformation", i))
		parse_transform_container(tokens, i, &camera->transformation);
	else if (accept(tokens[*i], "bounding_box", i))
		parse_int_container(tokens, i, &camera->visualize_bboxes,
				range(0, 1));
	else if (accept(tokens[*i], "anti_aliasing", i))
		parse_int_container(tokens, i, &camera->anti_aliasing,
				range(0, 1));
	else if (accept(tokens[*i], "sh_grain", i))
		parse_int_container(tokens, i, &camera->sh_grain,
				range(1, 100));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_camera(tokens, i, camera, max++);
}
