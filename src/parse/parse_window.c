/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:20:32 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"
#include "flags.h"

void	parse_window(char **tokens, int *i, t_window *window, int max_depth)
{
	if (tokens[*i] == NULL)
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	if (check(tokens[*i], "}") || max_depth == MAX_WINDOW_ELEMENTS)
	{
		return ;
	}
	if (accept(tokens[*i], "width", i))
		parse_int_container(tokens, i, &window->width, range(1, 1800));
	if (accept(tokens[*i], "height", i))
		parse_int_container(tokens, i, &window->height, range(1, 2550));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_window(tokens, i, window, max_depth++);
}
