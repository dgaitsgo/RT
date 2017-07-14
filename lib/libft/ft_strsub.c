/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 21:02:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*stuck;
	int				i;
	unsigned int	beg;

	beg = start;
	i = 0;
	stuck = (char *)malloc(sizeof(char) * (len + 1));
	if (stuck != NULL)
	{
		while (len > 0)
		{
			stuck[i] = s[beg];
			beg++;
			len--;
			i++;
		}
		stuck[i] = '\0';
	}
	return (stuck);
}
