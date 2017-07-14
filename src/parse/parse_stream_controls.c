/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stream_controls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:13:41 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	accept(char *candidate, char *expected, int *i)
{
	if (candidate && expected)
	{
		if (ft_strcmp(candidate, expected) == 0)
		{
			(*i)++;
			return (1);
		}
	}
	return (0);
}

int	check(char *candidate, char *possibility)
{
	if (candidate && possibility)
	{
		if (ft_strcmp(candidate, possibility) == 0)
			return (1);
		else
			return (0);
	}
	parse_error(UNEXPECTED_SYMBOL, NULL, 0);
	return (0);
}

int	expect(char *candidate, char *expected, int *i)
{
	if (accept(candidate, expected, i))
		return (1);
	else
		parse_error(UNEXPECTED_SYMBOL, NULL, 0);
	return (0);
}

int	next(char **tokens, char *candidate, int *i)
{
	(*i)++;
	if (tokens[*i])
		if (expect(tokens[*i], candidate, i))
			return (1);
	return (0);
}
