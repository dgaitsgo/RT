/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:07:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				pre_word(char *s, int *i)
{
	while (is_space(s[*i]))
	{
		(*i)++;
		if (s[*i] == '\0')
			return (-1);
	}
	return (1);
}

int				word(char *s, int *i)
{
	while (!is_space(s[*i]))
	{
		(*i)++;
		if (s[*i] == '\0')
			return (1);
	}
	return (0);
}

int				after_word(char *s, int *i, int word_found)
{
	while (is_space(s[*i]))
	{
		(*i)++;
		if (s[*i] == '\0')
			if (word_found == 1)
				return (1);
		if (!is_space(s[*i]))
			return (0);
	}
	return (0);
}

int				only_one_word(char *s)
{
	int		i;
	int		word_found;

	i = 0;
	word_found = 0;
	while (s[i])
	{
		if (pre_word(s, &i) == -1)
			return (-1);
		if (word(s, &i) == 1)
			return (1);
		word_found = 1;
		if (after_word(s, &i, word_found))
			return (1);
		else
			return (0);
		i++;
	}
	if (i && word_found)
		return (1);
	return (0);
}
