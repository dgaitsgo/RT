/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:03:04 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 19:53:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	int		i;

	i = 0;
	if (!(string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(string, 0, size + 1);
	return (string);
}
