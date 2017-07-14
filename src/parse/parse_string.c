/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:11:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		string_to_shape(char **tokens, int *i)
{
	int		shape;

	shape = SPHERE;
	if (expect(tokens[*i], "<", i))
	{
		if (accept(tokens[*i], "sphere", i))
			shape = SPHERE;
	}
	if (expect(tokens[*i], ">", i))
		;
	else
	{
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	}
	return (shape);
}
