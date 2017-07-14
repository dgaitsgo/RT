/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/13 14:14:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				valid_file_type(const char *file_name, const int fd)
{
	char		*extension;

	if (fd < 2)
		parse_error(BAD_FILE, NULL, NULL);
	extension = ft_strrchr(file_name, '.');
	if ((extension == NULL) || ft_strcmp(extension, ".rtsd") != 0)
		parse_error(BAD_FILE, NULL, NULL);
	return (1);
}

void			free_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int				parse(const char *file_name, t_scene *scene)
{
	char		*file_as_string;
	char		**tokens;
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (valid_file_type(file_name, fd))
	{
		file_as_string = file_to_string(fd);
		if (file_as_string)
		{
			file_as_string = remove_white_spaces(file_as_string);
			tokens = tokenize(file_as_string);
			if (parse_scene(tokens, scene))
			{
				free(file_as_string);
				free_tokens(tokens);
				return (1);
			}
		}
	}
	return (0);
}
