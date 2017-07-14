/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/19 15:07:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_error_tokens(char **tokens, int *i)
{
	int error_location;
	int cursor;

	if (i == NULL || tokens == NULL)
		return ;
	error_location = *i;
	ft_putnbr(error_location);
	cursor = *i < 10 ? 0 : *i - 10;
	ft_putstr("\nBad string:\n");
	while (cursor < error_location + 10)
	{
		if (!tokens || !tokens[cursor])
		{
			break ;
		}
		if (cursor == *i)
			ft_putstr("LOOK HERE:");
		ft_putstr(tokens[cursor]);
		ft_putstr(" ");
		cursor++;
	}
}

int		parse_error(int error, char **tokens, int *i)
{
	if (error == BAD_FILE)
		ft_putstr("File is not ray tracing scene description file\n");
	if (error == REPEAT_SYMBOL)
		ft_putstr("Repeat Symbol\n");
	if (error == UNEXPECTED_SYMBOL)
		ft_putstr("Unexpected Symbol\n");
	if (error == TOO_MANY_OBJECTS)
		ft_putstr("Too many objects\n");
	if (error == TOO_MANY_LIGHTS)
		ft_putstr("Too many lights\n");
	if (error == CONFLICTING_IDS)
		ft_putstr("Conflicting IDs\n");
	if (error == MEMORY_ERROR)
		ft_putstr("Malloc returned a NULL pointer\n");
	if (error == TEXTURE_ERROR)
		ft_putstr("Bad texture file\n");
	if (error == DEGENERATE_VALUE)
		ft_putstr("Degenerate value read\n");
	if (error == UNDERDETERMINED)
		ft_putstr("Not enough elements to depict\n");
	print_error_tokens(tokens, i);
	exit(0);
	return (0);
}

int		parse_warning(int error)
{
	if (error == CAMERA_UNDEFINED)
		ft_putstr("t_camera was not defined default position is used\n");
	if (error == NO_OBJECTS)
		ft_putstr("t_scene is empty\n");
	if (error == NO_LIGHTS)
		ft_putstr("t_scene has no lights\n");
	if (error == DENSE_SCENE)
		ft_putstr("t_scene is dense, rendering time require patience");
	return (0);
}
