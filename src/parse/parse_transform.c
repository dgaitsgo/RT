/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:11:12 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_transform(char **tokens,
		int *i,
		t_transform *field,
		int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_TRANSFORM_ELEMENTS)
	{
		return ;
	}
	if (accept(tokens[*i], "scale", i))
		parse_vector(tokens, i, &field->scale, range(1, FLT_MAX));
	else if (accept(tokens[*i], "rotation", i))
		parse_vector(tokens, i, &field->rotation, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "translation", i))
		parse_vector(tokens, i, &field->translation, range(-FLT_MAX, FLT_MAX));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_transform(tokens, i, field, max_depth++);
}

void	parse_transform_container(char **tokens, int *i, t_transform *field)
{
	if (expect(tokens[*i], "{", i))
	{
		parse_transform(tokens, i, field, 0);
		if (expect(tokens[*i], "}", i))
			;
	}
}
