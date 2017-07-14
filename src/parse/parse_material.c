/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/15 14:23:29 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_material(char **tokens, int *i, t_material *field, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_MATERIAL_ELEMENTS)
		return ;
	if (accept(tokens[*i], "color", i))
	{
		parse_vector(tokens, i, &field->texture.color_1, range(0, 255));
		rgb_to_normal(&field->texture.color_1);
	}
	else if ((accept(tokens[*i], "Texture", i)))
		parse_texture(tokens, i, &(field->texture));
	else if (accept(tokens[*i], "lambert", i))
		parse_double_container(tokens, i, &field->lambert, range(0, 1.0));
	else if (accept(tokens[*i], "specular", i))
		parse_double_container(tokens, i, &field->specular, range(0, 1.0));
	else if (accept(tokens[*i], "ambient", i))
		parse_double_container(tokens, i, &field->ambient, range(0, 1.0));
	else if (accept(tokens[*i], "refraction", i))
		parse_double_container(tokens, i, &field->refraction, range(0, 5.0));
	else if (accept(tokens[*i], "reflective", i))
		parse_double_container(tokens, i, &field->reflective, range(0, 1.0));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_material(tokens, i, field, max_depth++);
}

void	parse_material_container(char **tokens, int *i, t_material *field)
{
	if (expect(tokens[*i], "{", i))
	{
		parse_material(tokens, i, field, 0);
		if (expect(tokens[*i], "}", i))
			;
	}
}
