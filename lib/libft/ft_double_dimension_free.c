/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_dimension_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:33:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/04/27 20:33:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_dimension_free(void **ptr, int d)
{
	int i;

	i = 0;
	while (i < d)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
