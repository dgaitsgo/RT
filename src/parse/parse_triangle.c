/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:35:52 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		parse_triangle(char **tokens,
							int *i,
							t_object *object,
							int max_depth)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)object->shape;
	if (check(tokens[*i], "}") || max_depth == max_elements(object->type))
	{
		build_affine_group(&object->affine_group);
		return ;
	}
	if (accept(tokens[*i], "A", i))
		parse_vector(tokens, i, &triangle->v0, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "B", i))
		parse_vector(tokens, i, &triangle->v1, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "C", i))
		parse_vector(tokens, i, &triangle->v2, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "Transformation", i))
		parse_transform_container(tokens, i, &object->affine_group.trans_data);
	else if (accept(tokens[*i], "Material", i))
		parse_material_container(tokens, i, &object->material);
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_triangle(tokens, i, object, ++max_depth);
}
