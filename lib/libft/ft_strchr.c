/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:02:49 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 15:45:34 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*save;
	int		size;

	size = ft_strlen(s);
	ch = (char)c;
	while (size >= 0)
	{
		if (*s == ch)
		{
			save = &*(char *)s;
			return (save);
		}
		size--;
		s++;
	}
	return (NULL);
}
