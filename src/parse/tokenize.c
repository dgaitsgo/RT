/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:11:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char			**get_memory(int n, int length_table[1000])
{
	char	**final;
	int		i;

	i = 0;
	final = malloc(sizeof(char *) * (n + 1));
	final[n] = NULL;
	while (i < n)
	{
		final[i] = malloc(sizeof(char) * (length_table[i] + 1));
		final[i][length_table[i]] = '\0';
		i++;
	}
	return (final);
}

static void		write_in(char *s, char **tokens, int length_table[1000], int n)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (k < n)
	{
		j = 0;
		while (j < length_table[k])
		{
			tokens[k][j] = s[i];
			i++;
			j++;
		}
		k++;
	}
}

char			**tokenize(char *s)
{
	static int		length_table[1000];
	char			**tokens;
	int				n_words;

	n_words = count_words_and_length(s, length_table);
	tokens = get_memory(n_words, length_table);
	write_in(s, tokens, length_table, n_words);
	return (tokens);
}
