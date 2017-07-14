/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:32:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 22:40:15 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f' ||
		c == '\r')
		return (1);
	return (0);
}

static char	*write_to_trimmed(const char *s, char *trimmed, int beg, int end)
{
	int i;

	i = 0;
	while (end >= beg)
	{
		trimmed[i] = s[beg];
		i++;
		beg++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		beg;
	int		end;
	char	*trimmed;

	i = 0;
	while (is_space(s[i]) == 1 && s[i] != '\0')
		i++;
	beg = i;
	end = ft_strlen(s) - 1;
	if (beg - 1 == end)
		return (ft_strnew(1));
	if ((beg == 0 && is_space(s[end]) == 0))
		return (ft_strdup(s));
	while (is_space(s[end]) == 1)
		end--;
	if (!(trimmed = (char *)malloc(sizeof(char) * (end - beg + 1))))
		return (NULL);
	return (write_to_trimmed(s, trimmed, beg, end));
}
