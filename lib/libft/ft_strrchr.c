/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/15 15:11:15 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*save;
	int		end;

	ch = (char)c;
	end = ft_strlen(s);
	s += end;
	if (end > 0)
	{
		while (end > -1)
		{
			if (*s == ch)
			{
				save = &*(char *)s;
				return (save);
			}
			s--;
			end--;
		}
	}
	return (NULL);
}
