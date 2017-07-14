/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 20:51:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*d;
	const char	*s;
	int			i;
	int			j;

	d = s1;
	s = s2;
	i = 0;
	j = 0;
	while (d[i] != 0)
		i++;
	while (n > 0 && s[j])
	{
		d[i++] = s[j++];
		n--;
	}
	d[i] = '\0';
	return (s1);
}
