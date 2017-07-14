/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:06 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 22:30:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_length(const char *str, int beg, char c)
{
	int			length;

	length = 0;
	while (str[beg] != c)
	{
		if (str[beg] == '\0')
			return (length);
		beg++;
		length++;
	}
	return (length);
}

static int		*get_size(const char *str, char c)
{
	int			i;
	int			beg;
	static int	lt[256];

	i = 0;
	beg = 0;
	while (str[beg] != '\0')
	{
		while (word_length(str, beg, c) == 0)
		{
			beg++;
			if (str[beg] == '\0')
				return (lt);
		}
		lt[i] = word_length(str, beg, c);
		beg = beg + lt[i];
		i++;
	}
	return (lt);
}

static char		**get_mem(char **fs, int *lt, int words)
{
	int			i;

	i = 0;
	if (!(fs = (char **)malloc(words * (sizeof(char)) + 2000)))
		return (NULL);
	while (lt[i])
	{
		if (!(fs[i] = (char *)malloc(lt[i] * sizeof(char) + 2000)))
			return (NULL);
		i++;
	}
	return (fs);
}

static char		**write_into(char **fs, const char *str, int *lt, char c)
{
	int			i;
	int			a;
	int			j;

	a = 0;
	i = 0;
	j = 0;
	while (lt[i])
	{
		j = 0;
		while (word_length(str, a, c) == 0)
			a++;
		while (lt[i] > 0)
		{
			fs[i][j] = str[a];
			j++;
			a++;
			lt[i]--;
		}
		fs[i][j] = '\0';
		i++;
	}
	fs[i] = NULL;
	return (fs);
}

char			**ft_strsplit(const char *s, char c)
{
	int			*lt;
	char		**fs;
	int			words;

	fs = NULL;
	words = 0;
	lt = get_size(s, c);
	while (lt[words])
		words++;
	if (!(fs = get_mem(fs, lt, words)))
		return (NULL);
	fs = write_into(fs, s, lt, c);
	return (fs);
}
