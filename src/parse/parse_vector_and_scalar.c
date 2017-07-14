/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector_and_scalar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/13 14:48:15 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_double(char *token, double *field, double min, double max)
{
	double scalar;

	scalar = (double)atof(token);
	if (scalar >= min && scalar <= max)
	{
		*field = scalar;
	}
	else
		parse_error(DEGENERATE_VALUE, NULL, 0);
}

void	parse_int(char *token, int *field, int min, int max)
{
	int	scalar;

	scalar = (int)atoi(token);
	if (scalar >= min && scalar <= max)
		*field = scalar;
	else
		parse_error(DEGENERATE_VALUE, NULL, 0);
}

void	parse_double_container(char **tokens, int *i, double *field,
t_range range)
{
	if (expect(tokens[*i], "<", i))
	{
		parse_double(tokens[*i], field, range.min, range.max);
		if (next(tokens, ">", i))
			;
	}
}

void	parse_int_container(char **tokens, int *i, int *field,
t_range range)
{
	if (expect(tokens[*i], "<", i))
	{
		parse_int(tokens[*i], field, (int)range.min, (int)range.max);
		if (next(tokens, ">", i))
			;
	}
}

void	parse_vector(char **tokens, int *i, t_vector *field, t_range range)
{
	if (expect(tokens[*i], "<", i))
	{
		parse_double(tokens[*i], &field->x, range.min, range.max);
		if (next(tokens, ",", i))
			parse_double(tokens[*i], &field->y, range.min, range.max);
		if (next(tokens, ",", i))
			parse_double(tokens[*i], &field->z, range.min, range.max);
		if (next(tokens, ">", i))
			;
	}
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
}
