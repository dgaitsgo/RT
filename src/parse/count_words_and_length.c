/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_and_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/05 19:22:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			capitalized_word(char *s, int *i, int j)
{
	(*i)++;
	while (lower_case_letter(s[*i]))
	{
		(*i)++;
		j++;
	}
	return (j);
}

int			numerical_word(char *s, int *i, int j)
{
	(*i)++;
	while (is_digit(s[*i]))
	{
		(*i)++;
		j++;
	}
	return (j);
}

int			file_path(char *s, int *i, int j)
{
	(*i)++;
	while (s[*i] != '"')
	{
		(*i)++;
		j++;
	}
	j--;
	(*i)++;
	return (j);
}

int			special_letter(char c)
{
	if (c == '.' || c == ',' || c == '_' || c == '/')
		return (1);
	return (0);
}

int			count_words_and_length(char *s, int length_table[1000])
{
	int i;
	int	n;

	initialize_to_zero_2(&i, &n);
	while (s[i])
	{
		if (capital_letter(s[i]))
			length_table[n++] = capitalized_word(s, &i, 1);
		if (lower_case_letter(s[i]))
			length_table[n++] = capitalized_word(s, &i, 1);
		if (is_digit(s[i]))
			length_table[n++] = numerical_word(s, &i, 1);
		if (s[i] == '"')
		{
			length_table[n++] = 1;
			length_table[n++] = file_path(s, &i, 1);
			length_table[n++] = 1;
		}
		if (s[i] == ',' || balancing_symbol(s[i]))
		{
			length_table[n++] = 1;
			i++;
		}
	}
	return (n);
}
