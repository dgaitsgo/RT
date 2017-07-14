/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/21 17:00:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_light(char **tokens, int *i, int max, t_scene *scene)
{
	t_light *light;
	char	*type;

	if (scene->n_lights > 1)
		parse_error(TOO_MANY_LIGHTS, tokens, i);
	light = scene->light[scene->n_lights];
	if (check(tokens[*i], "}") || max == MAX_LIGHT_ELEMENTS)
	{
		rgb_to_normal(&scene->light[scene->n_lights]->color);
		scene->n_lights++;
		return ;
	}
	else if (accept(tokens[*i], "Transformation", i))
	{
		parse_transform_container(tokens, i,
			&scene->light[scene->n_lights]->transformation);
		scene->light[scene->n_lights]->position =
			scene->light[scene->n_lights]->transformation.translation;
	}
	else if (accept(tokens[*i], "color", i))
		parse_vector(tokens, i, &light->color,
		range(0, 255));
	else
		parse_error(UNEXPECTED_SYMBOL, tokens, i);
	parse_light(tokens, i, max++, scene);
}
