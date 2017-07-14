/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:18:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int					load_file(char *name, t_texture *texture)
{
	SDL_Surface		*tmp;
	SDL_PixelFormat	*format;
	char			*complete_name;

	complete_name = ft_memalloc(sizeof(char) * (ft_strlen(name) + 13));
	ft_strcpy(complete_name, "texture/");
	ft_strcpy(complete_name + 8, name);
	ft_strcpy(complete_name + ft_strlen(name) + 8, ".bmp");
	if (texture->type == EXTERN)
	{
		tmp = SDL_LoadBMP(complete_name);
		free(complete_name);
		if (tmp == NULL)
			return (-1);
		format = SDL_AllocFormat(SDL_PIXELFORMAT_ABGR8888);
		if ((texture->text_img = SDL_ConvertSurface(tmp, format, 0)) == NULL)
		{
			SDL_FreeSurface(tmp);
			return (-2);
		}
		SDL_FreeSurface(tmp);
		return (1);
	}
	else
		return (0);
}

void				parse_texture_type(char **tokens, int *i, t_texture *field)
{
	if (expect(tokens[*i], "\"", i))
	{
		if (accept(tokens[*i], "simple", i))
			field->type = SIMPLE;
		else if (accept(tokens[*i], "extern", i))
			field->type = EXTERN;
		else if (accept(tokens[*i], "marble", i))
			field->type = MARBLE;
		else if (accept(tokens[*i], "pure", i))
			field->type = PURE_NOISE;
		else if (accept(tokens[*i], "wood", i))
			field->type = WOOD;
		if (!expect(tokens[*i], "\"", i))
			parse_error(UNEXPECTED_SYMBOL, tokens, i);
	}
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
}

void				parse_file_name(char **tokens, int *i, t_texture *field)
{
	int				ret;

	if (expect(tokens[*i], "\"", i))
	{
		ret = load_file(tokens[*i], field);
		(*i)++;
		if (ret == 1)
		{
			if (expect(tokens[*i], "\"", i))
				;
		}
		else
			parse_error(TEXTURE_ERROR, tokens, i);
	}
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
}

void				parse_texture_container(char **tokens, int *i,
								t_texture *field, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_TEXTURE_ELEMENTS)
		return ;
	if (accept(tokens[*i], "color_a", i))
	{
		parse_vector(tokens, i, &field->color_1, range(0, 255));
		rgb_to_normal(&field->color_1);
	}
	else if (accept(tokens[*i], "color_b", i))
	{
		parse_vector(tokens, i, &field->color_2, range(0, 255));
		rgb_to_normal(&field->color_2);
	}
	else if (accept(tokens[*i], "repetition", i))
		parse_vector(tokens, i, &field->repetition, range(DBL_MIN, DBL_MAX));
	else if (accept(tokens[*i], "turb_size", i))
		parse_double_container(tokens, i, &field->turb_size, range(0, 255));
	else if (accept(tokens[*i], "turb_power", i))
		parse_double_container(tokens, i, &field->turb_power, range(0, 255));
	else if (accept(tokens[*i], "type", i))
		parse_texture_type(tokens, i, field);
	else if (accept(tokens[*i], "type", i))
		parse_texture_type(tokens, i, field);
	else if (accept(tokens[*i], "file", i))
		parse_file_name(tokens, i, field);
	parse_texture_container(tokens, i, field, max_depth + 1);
}

void				parse_texture(char **tokens, int *i, t_texture *field)
{
	if (expect(tokens[*i], "{", i))
	{
		parse_texture_container(tokens, i, field, 0);
		if (expect(tokens[*i], "}", i))
			;
	}
}
