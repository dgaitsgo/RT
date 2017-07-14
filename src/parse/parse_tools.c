/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:11:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				in_comments(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
		{
			if (s[i + 1])
			{
				if (s[i + 1] == '/')
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

int				only_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}
