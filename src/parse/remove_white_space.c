/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_white_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:11:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			cut_word_from(int *i, int *beg, int *end, char *s)
{
	while (is_space(s[*i]))
	{
		(*i)++;
		if (s[*i] == '\0')
		{
			*end = 0;
			*beg = 0;
			return ;
		}
	}
	*beg = *i;
	while (!is_space(s[*i]))
	{
		(*i)++;
		if (s[*i] == '\0')
		{
			*end = *i;
			return ;
		}
	}
	*end = *i;
}

static char		*write_in(int total, int length_table[256],
char *s, char *final)
{
	int	i;
	int beg;
	int end;
	int	w;

	w = 0;
	i = 0;
	while (i < total)
	{
		beg = length_table[w];
		end = length_table[w + 1] + beg;
		while (beg < end)
		{
			final[i] = s[beg];
			beg++;
			i++;
		}
		w += 2;
	}
	free(s);
	return (final);
}

static char		*get_memory(int length_table[256], char *s, int max)
{
	char	*final;
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < max)
	{
		total += length_table[i + 1];
		i += 2;
	}
	if (total == 0)
		return (NULL);
	final = malloc(sizeof(char) * total + 1);
	final[total] = '\0';
	return (write_in(total, length_table, s, final));
}

char			*remove_white_spaces(char *s)
{
	static	int length_table[256];
	int			i;
	int			w;
	int			beg;
	int			end;

	i = 0;
	w = 0;
	while (s[i])
	{
		cut_word_from(&i, &beg, &end, s);
		if (end - beg)
		{
			w += 2;
			length_table[w - 2] = beg;
			length_table[w - 1] = end - beg;
		}
	}
	return (get_memory(length_table, s, w));
}
