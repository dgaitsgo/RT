/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:02:36 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/19 15:03:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*sc;

	sc = s;
	while (n)
	{
		if (*sc == (unsigned char)c)
			return ((unsigned char *)&(*sc));
		sc++;
		n--;
	}
	return (NULL);
}
